void print_vectors(int *dist, int *prev, int *selectat, int *heap, int n)
{
	int i;
	printf("\n***Printing vectors***\n-dist: ");
	for(i=0; i<n; i++)												
		printf("%d ", dist[i]);
	printf("\n\n-prev: ");
	for(i=0; i<n; i++)
		printf("%d ", prev[i]);
	printf("\n\n-selectat: ");
	for(i=0; i<n; i++)													
		printf("%d ", selectat[i]);
	printf("\n\n-Heap: ");
	for(i=0; i<n; i++)													
		printf("%d ", heap[i]);
	printf("\n\n");	
}