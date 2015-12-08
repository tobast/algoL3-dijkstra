#include <stdio.h>
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

