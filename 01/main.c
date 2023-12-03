/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:47:02 by borban            #+#    #+#             */
/*   Updated: 2023/12/03 18:21:31 by borban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main()
{
	FILE *fptr;
	char buf[100];
	char nums[1000][100];

	fptr = fopen("input", "r");

	if (fptr == NULL)
	{
		printf("The file is not opened. The program will "
				"now exit.");
		exit(0);
	}
	//we should get:
	//9,3
	//1,1
	//6,4
	//9,9
	//5,2
	while (fscanf(fptr, "%s ", buf) == 1)
	{
		//printf("%s\n", buf);
		int line = 0;		
		int i = 0;
		while (buf[i])
		{
			//write(1, &buf[i], 1);
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				write(1, &buf[i], 1);
				nums[line][0] = buf[i];
				break ;
			}
			i++;
		}
		int j = strlen(buf);
		printf("j=%d\n", j);
		while (j >= 0)
		{
			//write(1, &buf[j - 1], 1);
			if (buf[j - 1] >= '0' && buf[j - 1] <= '9')
			{
				write(1, &buf[j - 1], 1);
				nums[line][1] = buf[j - 1];
				break ;
			}
			j--;
		}
		write(1, "\n", 1);
		line++;
	}
}
