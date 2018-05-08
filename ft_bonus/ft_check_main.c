
int			main(int argc, char **argv)
{
	t_option	*option;

	option = NULL;
	option = ft_create_option(option);
	argv = ft_find_option(&argc, argv, option);
	if (option->h)
		ft_op_help(option, push);
	commands = ft_read_and_print(option, str, push, 0);
	if (option->l)
		ft_printf("Length of stack is {sea wave}%d{eoc}.\n\n", len);
	if (option->n)
		ft_printf("Number of commands is {sea wave}%d{eoc}.\n\n", commands);
	free(option);
}
