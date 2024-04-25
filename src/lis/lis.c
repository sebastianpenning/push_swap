#include "../../inc/push_swap.h"

void is(int *stack_c, int *lis, int len)
{
	int index;
	int inner_index;
	int value;

	index = len;
	inner_index = index;
	while (index >= 0)
	{
		value = stack_c[index];
		while(inner_index <= len)
		{
			if(stack_c[inner_index] > value)
			{
				value = stack_c[inner_index];
				lis[index] += 1;
			}
			inner_index++;
		}
		index--;
		inner_index = index;
	}
}


void init_lis_stack(t_pslist **stack_a)
{
	t_pslist *temp;
	int	val;
	
	temp = *stack_a;
	temp->lis = 1;
	val = temp->content;
	while(temp != NULL)
	{
		if (temp->content > val)
		{
			val = temp->content;
			temp->lis = 1;
		}
		temp = temp->next;
	}
}

void init_lis(t_pslist **stack_a, int *lis, int len)
{
	int index;
	int max;
	int index_of_max;
	t_pslist *temp = (*stack_a);

	index = 0;
	(void)stack_a;
	max = lis[0];
	index_of_max = 0;
	while(index <= len)
	{
		if(lis[index] > max)
		{
			max = lis[index];
			index_of_max = index;
		}
		index++;
	}
	while (index_of_max > 0)
	{
		temp = temp->next;
		index_of_max--;
	}
	init_lis_stack(&temp);
}

void lis(t_pslist**stack_a)
{
	int *stack_c;
	int *lis;
	int len;

	len = ps_lstsize((*stack_a)) - 1;
	lis = malloc(sizeof(int) * len);
	if (lis == NULL)
		exit(EXIT_FAILURE);
	stack_c = malloc(sizeof(int) * ps_lstsize((*stack_a)));
	init_c(stack_a, stack_c);
	is(stack_c, lis, len);
	free(stack_c);
	init_lis(stack_a, lis, len);
	free(lis);
}

int push_b_lis(t_pslist **stack_a, t_pslist **stack_b, int n)
{
	int index;
	int moves;

	moves = 0;
	index = 0;
	while(index < n)
	{
		if((*stack_a)->lis == 0)
		{
			push(stack_a, stack_b, pa);
			moves++;
		}
		else
		{
			rotate(stack_a, ra);
			moves++;
		}
			index++;
	}
	return(moves);
}