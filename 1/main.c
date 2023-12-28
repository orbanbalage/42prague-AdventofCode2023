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
	char nums[1000][3];
	int result;
	int line = 0;		
	int i = 0;
	char days[9][2][6] = {{"1", "one"}, {"2", "two"}, {"3", "three"}, {"4", "four"},
		{"5", "five"}, {"6", "six"}, {"7", "seven"}, {"8", "eight"}, {"9", "nine"}};
	//printf("days[2][0], days[3][1], days[7][0], days[7][1]: %s, %s, %s, %s\n", 
			days[2][0], days[3][1], days[7][0], days[7][1]);

	fptr = fopen("input", "r");

	if (fptr == NULL)
	{
		printf("The file is not opened. The program will "
				"now exit.");
		exit(0);
	}

	//Read file into array v1:
	while (fscanf(fptr, "%s ", buf) == 1)
	{
		while (buf[i])
		{
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				nums[line][0] = buf[i];
				break ;
			}
			i++;
		}
		i = 0;
		int j = strlen(buf);
		while (j >= 0)
		{
			if (buf[j - 1] >= '0' && buf[j - 1] <= '9')
			{
				nums[line][1] = buf[j - 1];
				break ;
			}
			j--;
		}
		line++;
	}

	//Iterate through array and calculate the result v1:
	int k = 0;
	result = 0;
	char *temp = malloc(3);
	while (*nums[k])
	{
		temp[0] = nums[k][0];
		temp[1] = nums[k][1];
		temp[2] = '\0';
		result += atoi(temp);
		k++;
	}
	printf("Result = %d\n", result);
	free(temp);

	
	fclose(fptr);
	//return (result);
}
