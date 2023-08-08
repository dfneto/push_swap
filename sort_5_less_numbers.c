#include "push_swap.h"

void	push_the_min_value_to_list_b(t_list **first, t_list **first_b)
{
	int min_index = get_min_index(*first); //TODO: acho que posso fazer hard code a posicao 0 e 1 porque sempre vao ser os dois menores indices
	while((*first)->index != min_index) //primeira posição
	{
		if((*first)->next->index == min_index) //segunda posicao
			swap(first, 'a');
		else if((*first)->next->next->index == min_index) //terceira posicao
			rotate(first, 'a');
		else //quarta e quinta posicao
			reverse_rotate(first, 'a');
	}
	if (list_is_ordered(*first)) //aqui first é um **, se eu passsar somente first estou passando um **, então tenho que passar somente um nó que é *
		exit(0);
	push(first, first_b, 'b');
}

void	sort_2_numbers(char *argv[])
{
	t_list *first = create_node(atoi(argv[1]));
	t_list *second = create_node(atoi(argv[2]));
	add_node_back(&first, second);

	if (first->value > second->value)
		swap(&first, 'a');
	//print_list(first);
}

//TODO: aqui devo receber um **first porque vou alterar o first
//void	sort_3_numbers(char *argv[])
void	sort_3_numbers(t_list **first, t_list *second, t_list *third)
{
	/*t_list *first = create_node(atoi(argv[1]));
	t_list *second = create_node(atoi(argv[2]));
	t_list *third = create_node(atoi(argv[3]));
	add_node_back(&first, second);
	add_node_back(&first, third);
	*/
	if(list_is_ordered(*first))
		exit(0);
	if ((*first)->value > second->value && second->value < third->value && third->value > (*first)->value) //2 1 3
		swap(first, 'a');
	else if ((*first)->value > second->value && second->value > third->value && third->value < (*first)->value) //3 2 1
	{
		swap(first, 'a');
		reverse_rotate(first, 'a');
	}
	else if ((*first)->value > second->value && second->value < third->value && third->value < (*first)->value) //3 1 2
		rotate(first, 'a');
	else if ((*first)->value < second->value && second->value > third->value && third->value > (*first)->value) //1 3 2
	{
		swap(first, 'a');
		rotate(first, 'a');
	}
	else if ((*first)->value < second->value && second->value > third->value && third->value < (*first)->value) //2 3 1
		reverse_rotate(first, 'a');
	//print_list(*first);
}

void	sort_5_numbers(char *argv[], int len)
{
	t_list *first = create_node(atoi(argv[1])); //aqui first é um nó, ou seja, um ponteiro para uma estrutura t_list, ou seja, armazena o endereço da t_list.
	t_list *first_b = NULL;
	t_list *node;

	int i = 2;
	while(i <= len)
	{
		node = create_node(atoi(argv[i++]));
		add_node_back(&first, node);
	}
	
	//TODO: se eu receber 5 1 2 3 4 vou fazer um monte de movimentos quando só deveria fazer um rotate. 
	//Talvez deva antes de fazer 5 movimentos (5 eh o minimo de movimentos que vou fazer quando só tenho um número fora de ordem), 
	//posso antes tentar ordenar com até 4 movimento e se conseguir não prossigo.
	// Mas tbm isso pode ser o mesmo que testar muitas possibilidades e escolher a melhor o que no final vou também gastar processamento.
	if (list_is_ordered(first)) 
		exit(0);
	set_the_index_to_the_list(first, len);
	push_the_min_value_to_list_b(&first, &first_b);
	if (len == 5)
		push_the_min_value_to_list_b(&first, &first_b);
	sort_3_numbers(&first, first->next, first->next->next);	
	push(&first_b, &first, 'a');
	if (len == 5)
		push(&first_b, &first, 'a');

	// print_list(first);
}
