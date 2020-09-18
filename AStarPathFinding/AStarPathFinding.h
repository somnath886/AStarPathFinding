#pragma once

typedef struct node {

	int val;
	int i;
	int j;
	double g;
	double h;
	double f;
	struct node* up;
	struct node* down;
	struct node* left;
	struct node* right;

}node;

/*Function Prototypes*/

bool openListIncludes(node** openList, node* neighbour, int index);
bool openListNullCheck(node** openList);
bool closedListIncludes(node** closedList, node* item);
node* findUp(node** cellDetails, int y, int x);
node* findDown(node** cellDetails, int y, int x);
node* findLeft(node** cellDetails, int y, int x);
node* findRight(node** cellDetails, int y, int x);