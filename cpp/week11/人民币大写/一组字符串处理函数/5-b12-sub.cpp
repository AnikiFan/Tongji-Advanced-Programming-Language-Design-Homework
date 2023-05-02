/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
int tj_strlen(const char str[])
{
	int i = 0;
	while (str[i] != 0)
		i++;
	return i;
}

int tj_strcat(char s1[], const char s2[])
{
	int s1len, s2len, i;
	s1len = tj_strlen(s1);
	s2len = tj_strlen(s2);
	for (i = 0; i < s2len + 1; i++)//包含了尾零
		s1[s1len + i] = s2[i];
	return 0;
}
int tj_strncat(char s1[], const char s2[], const int len)
{
	int s1len, s2len, i;
	s1len = tj_strlen(s1);
	s2len = tj_strlen(s2);
	if (len > s2len)
		tj_strcat(s1, s2);
	else {
		for (i = 0; i < len; i++)
			s1[s1len + i] = s2[i];
		s1[s1len + s2len] = 0;
	}
	return 0;
}
int tj_strcpy(char s1[], const char s2[])
{
	int s1len, s2len, i;
	s1len = tj_strlen(s1);
	s2len = tj_strlen(s2);
	for (i = 0; i < s2len + 1; i++)//包含了尾零
		s1[i] = s2[i];
	return 0;
}
int tj_strncpy(char s1[], const char s2[], const int len)
{
	int s1len, s2len, i;
	s1len = tj_strlen(s1);
	s2len = tj_strlen(s2);
	if (len > s2len)
		for (i = 0; i < s2len; i++)//不含尾零
			s1[i] = s2[i];
	else
		for (i = 0; i < len; i++)//不含尾零
			s1[i] = s2[i];
	return 0;
}
int tj_strcmp(const char s1[], const char s2[])//应该s1-s2
{
	int i = 0;
	while (1) {
		if (s1[i] - s2[i] != 0)
			return s1[i] - s2[i];
		else if (s1[i] == 0 && s2[i] == 0)
			return 0;
		i++;
	}
}
int tj_strcasecmp(const char s1[], const char s2[])//应该s1-s2
{
	int i = 0, se1, se2;
	while (1) {
		if ('A' <= s1[i] && s1[i] <= 'Z')
			se1 = s1[i] - ('A' - 'a');
		else
			se1 = s1[i];
		if ('A' <= s2[i] && s2[i] <= 'Z')
			se2 = s2[i] - ('A' - 'a');
		else
			se2 = s2[i];

		if (se1 - se2 != 0)
			return se1 - se2;
		else if (se1 == 0 && se2 == 0)
			return 0;
		i++;
	}
}

int tj_strncmp(const char s1[], const char s2[], const int len)//应该s1-s2
{
	int s1len, s2len, i = 0, min = len;
	s1len = tj_strlen(s1);
	s2len = tj_strlen(s2);
	if (s1len + 1 < min)
		min = s1len + 1;
	if (s2len + 1 < min)
		min = s2len + 1;
	while (i < min) {
		if (s1[i] - s2[i] != 0)
			return s1[i] - s2[i];
		else if (s1[i] == 0 && s2[i] == 0)
			return 0;
		i++;
	}
	return 0;
}

int tj_strcasencmp(const char s1[], const char s2[], const int len)//应该s1-s2
{
	int s1len, s2len, i = 0, min = len, se1, se2;
	s1len = tj_strlen(s1);
	s2len = tj_strlen(s2);
	if (s1len + 1 < min)
		min = s1len + 1;
	if (s2len + 1 < min)
		min = s2len + 1;
	while (i < min) {
		if ('A' <= s1[i] && s1[i] <= 'Z')
			se1 = s1[i] - ('A' - 'a');
		else
			se1 = s1[i];
		if ('A' <= s2[i] && s2[i] <= 'Z')
			se2 = s2[i] - ('A' - 'a');
		else
			se2 = s2[i];

		if (se1 - se2 != 0)
			return se1 - se2;
		else if (se1 == 0 && se2 == 0)
			return 0;
		i++;
	}
	return 0;
}
int tj_strupr(char str[])
{
	int len = tj_strlen(str), i;
	for (i = 0; i < len; i++)
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] = str[i] + ('A' - 'a');
	return 0;
}
int tj_strlwr(char str[])
{
	int len = tj_strlen(str), i;
	for (i = 0; i < len; i++)
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] = str[i] - ('A' - 'a');
	return 0;
}
int tj_strchr(const char str[], const char ch)
{
	int i = 0;
	while (str[i] != ch && str[i] != 0)
		i++;
	if (str[i] == 0)
		return 0;
	return 1 + i;
}
int tj_strstr(const char str[], const char substr[])
{
	int i = 0, existflag = 1, j;
	while (str[i] != 0) {
		for (j = 0; j < tj_strlen(substr); j++)
			if (str[i + j] != substr[j])
				existflag = 0;
		if (existflag == 1)
			return i + 1;
		existflag = 1;
		i++;
	}
	return 0;
}
int tj_strrchr(const char str[], const char ch)
{
	int i = tj_strlen(str) - 1;
	while (str[i] != ch && i != -1)
		i--;
	if (i == -1)
		return 0;
	return 1 + i;
}
int tj_strrstr(const char str[], const char substr[])
{
	int i = tj_strlen(str) - 1, existflag = 1, j;
	while (i >= 0) {
		for (j = 0; j < tj_strlen(substr); j++)
			if (str[i + j] != substr[j])
				existflag = 0;
		if (existflag == 1)
			return i + 1;
		existflag = 1;
		i--;
	}
	return 0;
}

int tj_strrev(char str[])
{
	int i, len = tj_strlen(str);
	char temp;
	for (i = 0; i < len; i++) {
		if (i + 1 >= (len - 1 - i - 1))
			break;
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
	return 0;
}