#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/*Main*/

int main(void) {

	int arr[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	node** cellDetails = (node**)malloc(9 * sizeof(node*));
	node** openList = (node**)malloc(9 * sizeof(node*));
	node** closedList = (node**)malloc(9 * sizeof(node*));
	int winner = 0;

	for (int i = 0; i < 9; i++) {

		openList[i] = NULL;
		closedList[i] = NULL;

	}

	for (int i = 0; i < 9; i++) {

		cellDetails[i] = (node*)malloc(1 * sizeof(node));

	}

	int indexIncrement = 0;

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			cellDetails[indexIncrement + j]->val = arr[i][j];
			cellDetails[indexIncrement + j]->i = i;
			cellDetails[indexIncrement + j]->j = j;
			cellDetails[indexIncrement + j]->g = (double)i + (double)j;
			cellDetails[indexIncrement + j]->h = (2 - (double)i) + (2 - (double)j);
			cellDetails[indexIncrement + j]->f = cellDetails[indexIncrement + j]->g + cellDetails[indexIncrement + j]->h;

		}

		indexIncrement = indexIncrement + 3;

	}

	for (int i = 0; i < 9; i++) {

		if (cellDetails[i]->i != 0) {

			cellDetails[i]->up = findUp(cellDetails, cellDetails[i]->i, cellDetails[i]->j);

		}
		else {

			cellDetails[i]->up = NULL;

		}
		if (cellDetails[i]->i != 2) {

			cellDetails[i]->down = findDown(cellDetails, cellDetails[i]->i, cellDetails[i]->j);

		}
		else {

			cellDetails[i]->down = NULL;

		}
		if (cellDetails[i]->i != 0) {

			cellDetails[i]->left = findLeft(cellDetails, cellDetails[i]->i, cellDetails[i]->j);

		}
		else {

			cellDetails[i]->left = NULL;

		}
		if (cellDetails[i]->i != 2) {

			cellDetails[i]->right = findRight(cellDetails, cellDetails[i]->i, cellDetails[i]->j);

		}
		else {

			cellDetails[i]->right = NULL;

		}

	}

	openList[0] = cellDetails[0];
	int openListIndex = 1;
	int closedListIndex = 0;

	while (openListNullCheck(openList)) {

		for (int i = 0; i < openListIndex; i++) {

			if (openList[i]->f <= openList[winner]->f) {

				winner = i;

			}

		}

		node* current = openList[winner];
		closedList[closedListIndex] = current;
		closedListIndex++;

		if (current == cellDetails[8]) {

			printf("Done\n");
			break;

		}

		if (current->up != NULL) {

			node* neighbour = current->up; /*Up*/
			double tempG = current->g + ((double)neighbour->i - (double)current->i) + ((double)neighbour->j - (double)current->j);

			bool newPath = false;

			if (openListIncludes(openList, neighbour, openListIndex) == true) {

				if (tempG < neighbour->g) {

					neighbour->g = tempG;
					newPath = true;
				}

			}
			else {

				neighbour->g = tempG;
				newPath = true;
				openList[openListIndex] = neighbour;
				openListIndex++;

			}

			if (newPath) {

				neighbour->f = neighbour->g + neighbour->h;

			}

		}

		if (current->down != NULL) {

			node* neighbour = current->down; /*Down*/
			double tempG = current->g + ((double)neighbour->i - (double)current->i) + ((double)neighbour->j - (double)current->j);

			bool newPath = false;

			if (openListIncludes(openList, neighbour, openListIndex) == true) {

				if (tempG < neighbour->g) {

					neighbour->g = tempG;
					newPath = true;
				}

			}
			else {

				neighbour->g = tempG;
				newPath = true;
				openList[openListIndex] = neighbour;
				openListIndex++;

			}

			if (newPath) {

				neighbour->f = neighbour->g + neighbour->h;

			}

		}
		if (current->left != NULL) {

			node* neighbour = current->left; /*Left*/
			double tempG = current->g + ((double)neighbour->i - (double)current->i) + ((double)neighbour->j - (double)current->j);

			bool newPath = false;

			if (openListIncludes(openList, neighbour, openListIndex) == true) {

				if (tempG < neighbour->g) {

					neighbour->g = tempG;
					newPath = true;
				}

			}
			else {

				neighbour->g = tempG;
				newPath = true;
				openList[openListIndex] = neighbour;
				openListIndex++;

			}

			if (newPath) {

				neighbour->f = neighbour->g + neighbour->h;

			}

		}
		if (current->right != NULL) {

			node* neighbour = current->right; /*Right*/
			double tempG = current->g + ((double)neighbour->i - (double)current->i) + ((double)neighbour->j - (double)current->j);

			bool newPath = false;

			if (openListIncludes(openList, neighbour, openListIndex) == true) {

				if (tempG < neighbour->g) {

					neighbour->g = tempG;
					newPath = true;
				}

			}
			else {

				neighbour->g = tempG;
				newPath = true;
				openList[openListIndex] = neighbour;
				openListIndex++;

			}

			if (newPath) {

				neighbour->f = neighbour->g + neighbour->h;

			}

		}

	}

	for (int i = 0; i < 9; i++) {

		if (closedListIncludes(closedList, cellDetails[i])) {

			arr[cellDetails[i]->i][cellDetails[i]->j] = 1;

		}

	}

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			printf("%d", arr[i][j]);

		}
		printf("\n");

	}

	free(openList);
	free(closedList);
	for (int i = 0; i < 9; i++) {

		free(cellDetails[i]);

	}
	free(cellDetails);

}

/*Function Declarations Start Here*/

node* findUp(node** cellDetails, int y, int x) {

	for (int i = 0; i < 9; i++) {

		if (cellDetails[i]->i + 1 == y && cellDetails[i]->j == x) {

			return cellDetails[i];

		}

	}

	return NULL;

}

node* findDown(node** cellDetails, int y, int x) {

	for (int i = 0; i < 9; i++) {

		if (cellDetails[i]->i - 1 == y && cellDetails[i]->j == x) {

			return cellDetails[i];

		}

	}

	return NULL;

}

node* findLeft(node** cellDetails, int y, int x) {

	for (int i = 0; i < 9; i++) {

		if (cellDetails[i]->j + 1 == x && cellDetails[i]->i == y) {

			return cellDetails[i];

		}

	}

	return NULL;

}

node* findRight(node** cellDetails, int y, int x) {

	for (int i = 0; i < 9; i++) {

		if (cellDetails[i]->j - 1 == x && cellDetails[i]->i == y) {

			return cellDetails[i];

		}

	}

	return NULL;

}


bool openListIncludes(node** openList, node* neighbour, int index) {

	for (int i = 0; i < index; i++) {

		if (openList[i] == neighbour) {

			return true;

		}

	}

	return false;

}

bool closedListIncludes(node** closedList, node* item) {

	for (int i = 0; i < 9; i++) {

		if (closedList[i] == item) {

			return true;

		}

	}

	return false;

}

bool openListNullCheck(node** openList) {

	for (int i = 0; i < 9; i++) {

		if (openList[i] != NULL) {

			return true;

		}

	}

	return false;

}