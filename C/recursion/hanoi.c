#include <stdio.h>

int towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return 1;
    }
    
    int moves = 0;
    moves += towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    moves++;
    moves += towerOfHanoi(n - 1, auxiliary, source, destination);

    return moves;
}

int main() {
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    if (numDisks <= 0) {
        printf("Number of disks should be a positive integer.\n");
    } else {
        int totalMoves = towerOfHanoi(numDisks, 'A', 'B', 'C');
        printf("Total moves: %d\n", totalMoves);
    }

    return 0;
}
