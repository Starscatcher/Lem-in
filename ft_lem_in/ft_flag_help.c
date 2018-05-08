
#include "lem_in.h"

void	ft_help(t_data *data)
{
	ft_del_data(&data);
	ft_printf(" _________________{sea wave}<HELP>{eoc}_________________\n");
	ft_printf("|                                        |\n");
	ft_printf("|        ./lem-in [KEYS] [map]           |\n");
	ft_printf("|                                        |\n");
	ft_printf("|               {sea wave}---KEYS---{eoc}               |\n");
	ft_printf("|                                        |\n");
	ft_printf("|  {sea wave}[ -h ]{eoc}   help                         |\n");
	ft_printf("|  {sea wave}[ -w ]{eoc}   all ways                     |\n");
	ft_printf("|  {sea wave}[ -l ]{eoc}   length of each way           |\n");
	ft_printf("|  {sea wave}[ -s ]{eoc}   number of step               |\n");
	ft_printf("|  {sea wave}[ -r ]{eoc}   read from file               |\n");
	ft_printf("|  {sea wave}[ -o ]{eoc}   output in file               |\n");
	ft_printf("|  {sea wave}[ -c ]{eoc}   colour                       |\n");
	ft_printf("|                                        |\n");
	ft_printf("|           {red}START{eoc}                        |\n");
	ft_printf("|           {green}END{eoc}                          |\n");
	ft_printf("|________________________________________|\n");
	exit(0);
}
