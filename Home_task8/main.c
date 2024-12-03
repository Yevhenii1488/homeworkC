#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} point_t;

typedef struct {
    char name[50];
    int num_points;
    point_t *points;
} polygon_t;

polygon_t* read_polygons(const char *filename, int *polygon_count);
void print_polygons(const polygon_t *polygons, int polygon_count);
void free_polygons(polygon_t *polygons, int polygon_count);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    const char *filename = argv[1];
    int polygon_count = 0;

    polygon_t *polygons = read_polygons(filename, &polygon_count);
    if (!polygons) {
        printf("Failed to read polygons from file.\n");
        return 1;
    }

    print_polygons(polygons, polygon_count);

    free_polygons(polygons, polygon_count);

    return 0;
}


polygon_t* read_polygons(const char *filename, int *polygon_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    polygon_t *polygons = NULL;
    *polygon_count = 0;

    while (1) {
        polygon_t polygon;
        if (fscanf(file, "%49s", polygon.name) != 1) break;
        if (fscanf(file, "%d", &polygon.num_points) != 1) break;

        polygon.points = malloc(polygon.num_points * sizeof(point_t));
        if (!polygon.points) {
            perror("Memory allocation failed");
            fclose(file);
            return NULL;
        }

        for (int i = 0; i < polygon.num_points; i++) {
            if (fscanf(file, "%d %d", &polygon.points[i].x, &polygon.points[i].y) != 2) {
                perror("Error reading points");
                fclose(file);
                free(polygon.points);
                return NULL;
            }
        }

        polygons = realloc(polygons, (*polygon_count + 1) * sizeof(polygon_t));
        if (!polygons) {
            perror("Memory reallocation failed");
            fclose(file);
            free(polygon.points);
            return NULL;
        }

        polygons[*polygon_count] = polygon;
        (*polygon_count)++;
    }

    fclose(file);
    return polygons;
}

void print_polygons(const polygon_t *polygons, int polygon_count) {
    for (int i = 0; i < polygon_count; i++) {
        printf("Polygon: %s\n", polygons[i].name);
        printf("Points: ");
        for (int j = 0; j < polygons[i].num_points; j++) {
            printf("(%d, %d)", polygons[i].points[j].x, polygons[i].points[j].y);
            if (j < polygons[i].num_points - 1) printf(", ");
        }
        printf("\n");
    }
}

void free_polygons(polygon_t *polygons, int polygon_count) {
    for (int i = 0; i < polygon_count; i++) {
        free(polygons[i].points);
    }
    free(polygons);
}
