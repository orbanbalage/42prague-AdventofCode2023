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
		printf("Line %d: %s\n", line, buf);
		while (buf[i])
		{
			//write(1, &buf[i], 1);
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				//write(1, &buf[i], 1);
				nums[line][0] = buf[i];
				printf("<< Num inserted: %c\n", nums[line][0]);
				break ;
			}
			i++;
		}
		i = 0;
		int j = strlen(buf);
		//printf("j=%d\n", j);
		while (j >= 0)
		{
			//write(1, &buf[j - 1], 1);
			if (buf[j - 1] >= '0' && buf[j - 1] <= '9')
			{
				//write(1, &buf[j - 1], 1);
				nums[line][1] = buf[j - 1];
				printf(">> Num inserted: %c\n", nums[line][1]);
				break ;
			}
			j--;
		}
		//write(1, "\n", 1);
		printf("Processed line: %d\n\n", line);
		line++;
	}
	int k = 0;
	result = 0;
	while (*nums[k])
	{
		char temp[3] = "";
		//*nums[k] = malloc(sizeof(int) * 2);
		/*
		 *
		 * OK bug is isolated to here:
		 *
		 *
		strcpy(&temp[0], &nums[k][0]);
		strcpy(&temp[1], &nums[k][1]);
		*
		*
		*/
		//result += atoi(strcat(&nums[k][0], &nums[k][1]));
		printf("k, num: %d, %c%c\n", k, nums[k][0], nums[k][1]);
		printf("k, num, *temp[2]: %d, %c%c, %s\n", k, nums[k][0], nums[k][1], temp);
		printf("atoi temp: %d\n", atoi(temp));
		result += atoi(temp);
		printf("Result = %d\n", result);
		//printf("k = %d\n", k);
		k++;
		getchar();
	}
	printf("Result = %d\n", result);
}
