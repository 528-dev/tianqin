#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20

// 8 To build the Huffman Tree.
typedef struct HeapNode *Heap;
typedef struct BTNode *BinTree, *HuffmanTree;

typedef struct BTNode{
    int data, level;
    BinTree left, right;
}BTNode;

typedef struct HeapNode{
    BinTree elems[MAXSIZE];
    int size;
}HeapNode;

BinTree new_BinTree(int e){
    BinTree ret = (BinTree)malloc(sizeof(BTNode));
    ret->level = -1;
    ret->data = e;
    ret->left = ret->right = NULL;
    return ret;
}

Heap initHeap(){
    BinTree sentry = (BinTree)malloc(sizeof(BTNode));
    sentry->data = INT_MIN;
    sentry->left = sentry->right = NULL;
    Heap ret = (Heap)malloc(sizeof(HeapNode));
    ret->size = 0;
    ret->elems[0] = sentry;
    return ret;
}

int insertHeap(Heap hp, BinTree bt){
    int i;
    for (i = ++hp->size; (hp->elems)[i / 2]->data > bt->data; i /= 2)
        (hp->elems)[i] = (hp->elems)[i / 2];
    (hp->elems)[i] = bt;
    return 1;
}

BinTree deleteHeap(Heap hp){
    BinTree min = (hp->elems)[1];
    BinTree tmp = (hp->elems)[hp->size--];
    int i, child;
    for (i = 1; i * 2 <= hp->size; i = child){
        child = i * 2;
        if (child + 1 <= hp->size && (hp->elems)[child + 1]->data < (hp->elems)[child]->data) ++child;
        if ((hp->elems)[child]->data > tmp->data) break;
        (hp->elems)[i] = (hp->elems)[child];
    }(hp->elems)[i] = tmp;
    return min;
}

HuffmanTree buildHuffmanTree(Heap hp){
    int size = hp->size;
    BinTree leaf1, leaf2, parent;
    for (int i = 0; i < size - 1; ++i){
        leaf1 = deleteHeap(hp);
        leaf2 = deleteHeap(hp);
        parent = new_BinTree(leaf1->data + leaf2->data);
        parent->left = leaf1;
        parent->right = leaf2;
        insertHeap(hp, parent);
    }return hp->elems[1];
}

int levelTraHuff(HuffmanTree hft){
    BinTree tmp, queue[MAXSIZE];
    int top = -1, curlevel = -1, front = 0, rear = 0, sum = 0;
    hft->level = 0;
    queue[rear] = hft;
    rear = (rear + 1) % MAXSIZE;
    while (front != rear){
        tmp = queue[front];
        front = (front + 1) % MAXSIZE;
        if (curlevel != tmp->level){
            curlevel = tmp->level;
            printf("\n");
        }
        if (!tmp->left && !tmp->right) {
            putchar('*');
            sum += tmp->level * tmp->data;
        }
        printf("%d ", tmp->data);
        if (tmp->left){
            tmp->left->level = tmp->level + 1;
            queue[rear] = tmp->left;
            rear = (rear + 1) % MAXSIZE;
        }
        if (tmp->right){
            tmp->right->level = tmp->level + 1;
            queue[rear] = tmp->right;
            rear = (rear + 1) % MAXSIZE;
        }
    }
    printf("\n(Note the number with \"*\" is the leaves of huffman Tree.)\n\n");
    return sum;
}

// void addLeavesPathWithWeight(HuffmanTree hft, int *sum){
//     if (!hft->left && !hft->right){
//         *sum += hft->data * hft->level;
//         return;
//     }
//     addLeavesPathWithWeight(hft->left, sum);
//     addLeavesPathWithWeight(hft->right, sum);
// }

// int calPathWithWeight(HuffmanTree hft){
//     int ret = 0;
//     addLeavesPathWithWeight(hft, &ret);
//     return ret;
// }

void solution(){
    int e, sum;
    Heap hp = initHeap();
    HuffmanTree hft;
    printf("Please enter the elements:(type \'q\' to exit)\n");
    while (scanf("%d", &e)){
        insertHeap(hp, new_BinTree(e));
    }
    hft = buildHuffmanTree(hp);
    sum = levelTraHuff(hft);
    printf("the length of the path with weight: %d", sum);
}

int main(){
    solution();
}