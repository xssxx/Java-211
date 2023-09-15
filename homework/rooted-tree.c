#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOLDER 1
#define FILE 0

typedef struct node {
    char name[100];
    int size;
    int type; // 0 = file, 1 = folder
    int total_size;
    struct node* parent;
    struct node* firstChild;
    struct node* nextSibling;
} Node;

Node* createNode(char* name, int size, int type) {
    Node* node = (Node*) malloc(sizeof(Node));

    strcpy(node->name, name);
    node->size = size;
    node->type = type;
    node->total_size = 0;
    node->parent = NULL;
    node->firstChild = NULL;
    node->nextSibling = NULL;

    return node;
}

void addChild(Node* parent, Node* child) {
    if (parent == NULL || child == NULL) return;

    child->parent = parent;
    child->nextSibling = parent->firstChild;
    parent->firstChild = child;
}

void preorderTraversal(Node* node) {
    if (node == NULL) return;

    Node* child = node->firstChild;
    while (child != NULL) {
        preorderTraversal(child);
        child = child->nextSibling;
    }

    node->total_size = node->size;
    child = node->firstChild;
    while (child != NULL) {
        node->total_size += child->total_size;
        child = child->nextSibling;
    }
}

void postorderTraversal(Node* node) {
    if (node == NULL) return;

    Node* child = node->firstChild;
    while (child != NULL) {
        postorderTraversal(child);
        child = child->nextSibling;
    }

    printf("Name: %-20s total size: %dK\n", node->name, node->total_size);
}

void freeTree(Node* node) {
    if (node == NULL) return;

    Node* child = node->firstChild;
    while (child != NULL) {
        Node* nextChild = child->nextSibling;
        freeTree(child);
        child = nextChild;
    }

    free(node); 
}

int main() {
    Node* root = createNode("/user/rt/courses/", 1, FOLDER);

    Node* cs016 = createNode("cs016/", 2, FOLDER);
    Node* cs252 = createNode("cs252/", 1, FOLDER);

    Node* grades_cs016 = createNode("grades", 8, FILE);
    Node* homeworks = createNode("homeworks/", 1, FOLDER);
    Node* programs = createNode("programs/", 1, FOLDER);

    Node* projects = createNode("projects/", 1, FOLDER);
    Node* grades_cs252 = createNode("grades", 3, FILE);
    Node* papers = createNode("papers/", 1, FOLDER);
    Node* demos = createNode("demos/", 1, FOLDER);

    Node* hw1 = createNode("hw1", 3, FILE);
    Node* hw2 = createNode("hw2", 2, FILE);
    Node* hw3 = createNode("hw3", 4, FILE);
    Node* pr1 = createNode("pr1", 57, FILE);
    Node* pr2 = createNode("pr2", 97, FILE);
    Node* pr3 = createNode("pr3", 74, FILE);
    
    Node* buylow = createNode("buylow", 26, FILE);
    Node* sellhigh = createNode("sellhigh", 55, FILE);
    Node* market = createNode("market", 4786, FILE);

    addChild(root, cs016);
    addChild(root, cs252);

    addChild(cs016, grades_cs016);
    addChild(cs016, homeworks);
    addChild(cs016, programs);

    addChild(cs252, projects);
    addChild(cs252, grades_cs252);
    addChild(projects, papers);
    addChild(projects, demos);

    addChild(homeworks, hw1);
    addChild(homeworks, hw2);
    addChild(homeworks, hw3);

    addChild(programs, pr1);
    addChild(programs, pr2);
    addChild(programs, pr3);

    addChild(papers, buylow);
    addChild(papers, sellhigh);
    addChild(demos, market);

    printf("Total Sizes:\n");
    preorderTraversal(root); // set total size

    postorderTraversal(root);

    freeTree(root);

    return 0;
}
