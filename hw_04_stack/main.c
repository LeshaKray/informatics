#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
#include <locale.h>
#include <string.h>
check(const char* str)
{
	struct stack* s = NULL;
	int len = strlen(str), i;

	if (str[0] == '(')
		push(&s, str[0]);
	else if (str[0] == ')')
		return 0;

	if (str[0] == '{')
		push(&s, str[0]);
	else if (str[0] == '}')
		return 0;

	if (str[0] == '[')
		push(&s, str[0]);
	else if (str[0] == ']')
		return 0;

	for (i = 1; i < len; i++)
	{
		if (str[i] == '(')
			push(&s, str[i]);
		else if (str[i] == ')')
		{
			if (is_empty(&s))
				return 0;
			else
			{
				if (s->value == '(')
					pop(&s);
				else return 0;
			}
		}

		if (str[i] == '{')
			push(&s, str[i]);
		else if (str[i] == '}')
		{
			if (is_empty(&s))
				return 0;
			else
			{
				if (s->value == '{')
					pop(&s);
				else return 0;
			}

		}

		if (str[i] == '[')
			push(&s, str[i]);
		else if (str[i] == ']')
		{
			if (is_empty(&s))
				return 0;
			else
			{
				if (s->value == '[')
					pop(&s);
				else return 0;
			}
		}

	}

	if (is_empty(&s))
		return 1;
	else return 0;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	char str[100];
	int result;
	while (1)
	{
		printf("¬ведите последовательность:");
		gets_s(str, 100);
		result = check(str);
		if (result)
			printf("последовательность корректна\n");
		else printf("последовательность некорректна\n");
	}
	while (getchar() != '\n');
	return 0;
}