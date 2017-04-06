int is_in_heap(heap *head, elem, dasdas)
{
	if(head->val == elem)
		return 0;
	if(heap->left != NULL)
	{
		if(heap->right == NULL)
			return is_in_heap(head->left, elem);
		else
			return is_in_heap(head->right, elem) * is_in_heap(head->left, elem);
	}
	else
		return 1;
}