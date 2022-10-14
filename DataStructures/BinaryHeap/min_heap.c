#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Insert O(log n)
// Get-min O(1)
// Extract-min O(log n)

const int neutral = INT_MAX;
int left_child (int n) { return 2*n+1; }
int right_child (int n) { return 2*n+2; }
int parent (int n) { return ((n-1)/2); }

void swap(int* x, int* y){
    *(x) ^= *(y); *(y) ^= *(x); *(x) ^= *(y);
}

void print_tree(int *p, int n){
    int it = 1, idx = 0;
    n--;
    while(n){
        for(int i = 0; i < it && n; i++, idx++, n--){
            printf("%d ", (p[idx] != neutral ? p[idx] : 0));
        }
        it*=2;
        printf("\n");
    }
    printf("\n");
}

int main(){
    int n = 32;
    int size = 0;
    int *tree = malloc(4*n*(sizeof(int)));
    for(int i = 0; i < 4*n; i++){
        tree[i] = neutral;
    }
    int min;
    int next = 0;
    while(1){
        int op = 1;
        printf("(1) Insert\n");
        printf("(2) Get-Min\n");
        printf("(3) Extract-Min\n");
        printf("(4) Print tree\n");
        printf("(5) Exit\n");
        printf("Op: ");
        scanf("%d", &op);
        printf("\n");
        if( op == 1 ){
            // insert
            if(size == 31){
                printf("Full size!\n");
                printf("\n");
                continue;
            }
            int nu, pos = next, nop = 0;
            printf("Number to insert: ");
            scanf("%d", &nu);
            printf("\n");
            next++;
            tree[pos] = nu;
            size++;
            nop++;
            printf("-----------------\n");
            printf("Tree before balancing:\n");
            print_tree(tree, n);
            while(tree[parent(pos)] > tree[pos]){
                swap(&tree[parent(pos)], &tree[pos]);
                pos = parent(pos);
                nop++;
            }
            printf("Tree after balancing:\n");
            print_tree(tree, n);
            printf("Number of operations: %d\n", nop);
            printf("-----------------\n");
            printf("\n");
            min = tree[0];
        } else if ( op == 2 ){
            // get min
            if(size == 0){
                printf("Empty tree!\n");
                printf("\n");
                continue;
            }
            printf("Min: %d\n", min);
            printf("\n");
        } else if ( op == 3 ){
            // extract min
            if(size == 0){
                printf("Empty tree!\n");
                printf("\n");
                continue;
            }
            next--;
            int nop = 0, pos = next;
            swap(&tree[0], &tree[pos]);
            tree[pos] = neutral;
            size--;
            nop++;
            printf("-----------------\n");
            printf("Tree before balancing:\n");
            print_tree(tree, n);
            pos = 0;
            while(tree[pos] > tree[left_child(pos)] || tree[pos] > tree[right_child(pos)]){
                if(tree[left_child(pos)] <= tree[right_child(pos)]){
                    swap(&tree[pos], &tree[left_child(pos)]);
                    pos = left_child(pos);
                } else {
                    swap(&tree[pos], &tree[right_child(pos)]);
                    pos = right_child(pos);
                }
                nop++;
            }
            printf("Tree after balancing:\n");
            print_tree(tree, n);
            printf("Number of operations: %d\n", nop);
            printf("-----------------\n");
            printf("\n");
            min = tree[0];
        } else if ( op == 4 ){
            printf("-----------------\n");
            print_tree(tree, n);
            printf("-----------------\n");
        } else if ( op == 5 ){
            break;
        }
    }
    return 0;
}
