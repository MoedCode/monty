#include "monty.h"

char  **Tokenize_in_Arr(char *string, char*  delim)
{
	size_t TksNum = 0;
	char *token = NULL, **Tokens = NULL;

	token = strtok(string, delim);
	while (token)
	{

		Tokens = realloc(Tokens, sizeof(char *) * (TksNum + 1));

		if (!Tokens)
		{
			FREE_2D_ARR(Tokens);
			perror("tokenaize.c:21 realloc");
			return (NULL);
		}
	/* tokinize && Asign */
		Tokens[TksNum] = strdup(token);
		token = strtok(NULL, delim);
		TksNum++;


	}

		Tokens = realloc(Tokens, (sizeof(char *) * (TksNum + 1)));
		if (!Tokens)
		{
			FREE_2D_ARR(Tokens);
			perror("tokenaize.c:21 realloc");
			return (NULL);
		}


		Tokens[TksNum] = NULL;

			return (Tokens);
}

size_t Print_2D_Arr(char** array, size_t isNull)
{
	size_t i, j;

	if (!array)
		return (0);
	if (isNull >  0)
		j = isNull;
	else if (isNull == 0)
		for (j = 0; array[j]; j++)
			if (array[j] == NULL)
				return (0);

	for (i = 0; i < j; i++)
		printf("[%u] - %s  \n", (unsigned int)i,array[i]);

	return (i);
}