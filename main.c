#include <stdio.h>

/* DEBUG --- LinkedList testing
#include "linkedLists.h"

int main(void) {
	LinkedList* ll = ll_create(0);
	int running = 1;
	
	while(running) {
		char act = getchar();
		while(getchar() != '\n');

		switch(act) {
			case 'n':
				ll = ll->next;
				break;
			case 'p':
				ll = ll->prev;
				break;
			case 'q':
				running = 0;
				break;
			case 'd':
				printf("%d\n", ll->val);
				break;
			case 'i':
				ll_insert_next(ll, 0);
				scanf("%d", &(ll->next->val));
				break;
			case 's':
				ll_delete_next(ll);
				break;
			default:
				fprintf(stderr, "This action does not exists, you fool.\n");
				break;
		}
	}

	ll_clean(ll);
	return 0;
}
*****************************************************************************/

/*
#include "extendLists.h"

int main(void) {
	ExtendList l = el_create(1);
	int running = 1;
	while(running) {
		char act = getchar();
		int val;
		while(act == '\n') act=getchar();
		switch(act) {
			case 'l':
				for(int pos=0; pos < l.curLength; pos++)
					printf("%d ", (l.list)[pos]);
				puts("");
				break;
			case 'a':
				scanf("%d", &val);
				el_push_back(&l, val);
				printf("cur=%d avail=%d\n", l.curLength, l.availLength);
				break;
			case 'd':
				printf("Popped %d, ", (l.list)[l.curLength-1]);
				el_pop_back(&l);
				printf("cur=%d avail=%d\n", l.curLength, l.availLength);
				break;
			case 'q':
				running=0;
				break;
			default:
				printf("Unknown command.\n");
		}
	}
	el_clean(&l);
	return 0;
}
*************** TEST EXTENDLISTS ********************************************/


#include "fiboHeap.h"
#include "genericStruct.h"

void dfsPrint(Tree* cur, Tree* parent) {
	if(parent == NULL)
		printf("%d root\n", cur->val.graphNode);
	else
		printf("%d -> %d\n", parent->val.graphNode, cur->val.graphNode);

	if(cur->sibling != NULL)
		dfsPrint(cur->sibling, parent);
	if(cur->child != NULL)
		dfsPrint(cur->child, cur);
}

void fullPrint(FiboHeap* fh) {
	dfsPrint(fh->trees->val, NULL);
	for(LinkedList* it = fh->trees->next ; it != fh->trees; it=it->next)
		dfsPrint(fh->trees->val, NULL); 
}

int main(void) {
	FiboHeap fh = fh_create();
	short running = true;
	while(running) {
		char act = getchar();
		while(act == '\n') { act = getchar(); }

		TreeNode val;

		switch(act) {
			case 'm':
				val = fh_extractMin(&fh);
				printf("Min: %d of weight %d\n", val.graphNode, val.weight);
				break;
			case 'i':
				scanf("%d %d", &(val.graphNode), &(val.weight));
				fh_insert(&fh, val);
			case 'c':
				val = fh_getMin(&fh);
				printf("Min: %d of weight %d\n", val.graphNode, val.weight);
				break;
			case 'f':
				fullPrint(&fh);
				break;
			case 'q':
				running = false;
				break;
		}
	}
	return 0;
}

