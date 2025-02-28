/* 2254298 范潇 信11 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return 0;
	const char* p = str;

	while (*p != '\0')
		p++;
	return p - str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int length = tj_strlen(s1);
	char* p = s1;
	if (s1 == NULL || s2 == NULL)
		return s1;
	while (p - s1 < length)
		p++;
	while (*s2 != '\0')
		*p++ = *s2++;
	*p = '\0';
	return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	char* p = s1;
	const char* p2 = s2;
	if (s1 == NULL || s2 == NULL)
		return s1;
	if (len2 <= len) {
		while (p - s1 < len1)
			p++;
		while (*s2 != '\0')
			*p++ = *s2++;
		*p = '\0';
	}
	else {
		while (p - s1 < len1)
			p++;
		while (*s2 != '\0' && s2 - p2 <= len - 1)
			*p++ = *s2++;
		*p = '\0';
	}
	return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL)
		return s1;
	if (s2 == NULL) {
		*s1 = '\0';
		return s1;
	}
	int len2 = tj_strlen(s2);

	char* p1 = s1;

	while (*p1++ = *s2++)
		;
	return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
	if (s1 == NULL)
		return s1;
	if (s2 == NULL)
		return s1;
	char* p1 = s1;
	int len2 = tj_strlen(s2);

	if (len2 <= len)
		while (*s2 != '\0')
			*p1++ = *s2++;
	else
		while (p1 - s1 < len)
			*p1++ = *s2++;
	return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL && s2 != NULL)
		return -1;
	else if (s1 != NULL && s2 == NULL)
		return 1;
	else if (s1 == NULL && s2 == NULL)
		return 0;
	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 - *s2 != 0)
			return *s1 - *s2;
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	char low1, low2;
	if (s1 == NULL && s2 != NULL)
		return -1;
	else if (s1 != NULL && s2 == NULL)
		return 1;
	else if (s1 == NULL && s2 == NULL)
		return 0;
	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 >= 'A' && *s1 <= 'Z')
			low1 = *s1 - ('A' - 'a');
		else
			low1 = *s1;
		if (*s2 >= 'A' && *s2 <= 'Z')
			low2 = *s2 - ('A' - 'a');
		else
			low2 = *s2;
		if (low1 - low2 != 0)
			return low1 - low2;
		s1++;
		s2++;
	}
	if (*s1 >= 'A' && *s1 <= 'Z')
		low1 = *s1 - ('A' - 'a');
	else
		low1 = *s1;
	if (*s2 >= 'A' && *s2 <= 'Z')
		low2 = *s2 - ('A' - 'a');
	else
		low2 = *s2;
	return *s1 - *s2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	if (len > len1 || len > len2)
		return tj_strcmp(s1, s2);
	if (s1 == NULL && s2 != NULL)
		return -1;
	else if (s1 != NULL && s2 == NULL)
		return 1;
	else if (s1 == NULL && s2 == NULL)
		return 0;
	const char* p1 = s1;
	while (s1 - p1 < len) {
		if (*s1 - *s2 != 0)
			return *s1 - *s2;
		s1++;
		s2++;
	}
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	char low1, low2;
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	if (len > len1 || len > len2)
		return tj_strcasecmp(s1, s2);
	if (s1 == NULL && s2 != NULL)
		return -1;
	else if (s1 != NULL && s2 == NULL)
		return 1;
	else if (s1 == NULL && s2 == NULL)
		return 0;
	const char* p1 = s1;
	while (s1 - p1 < len) {
		if (*s1 >= 'A' && *s1 <= 'Z')
			low1 = *s1 - ('A' - 'a');
		else
			low1 = *s1;
		if (*s2 >= 'A' && *s2 <= 'Z')
			low2 = *s2 - ('A' - 'a');
		else
			low2 = *s2;
		if (low1 - low2 != 0)
			return low1 - low2;
		if (low1 - low2 != 0)
			return low1 - low2;
		s1++;
		s2++;
	}
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	char* output = str;
	if (str == NULL)
		return str;
	while (*str != '\0') {
		if (*str >= 'a' && *str <= 'z')
			*str += 'A' - 'a';
		str++;
	}
	return output;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	char* output = str;
	if (str == NULL)
		return str;
	while (*str != '\0') {
		if (*str >= 'A' && *str <= 'Z')
			*str += 'a' - 'A';
		str++;
	}
	return output;
	return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return 0;
	const char* p = str;
	while (*str != '\0') {
		if (*str == ch)
			return str - p + 1;
		str++;
	}
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL || substr == NULL)
		return 0;
	bool isSub;
	const char* p = str, * psub = substr, * pcmp, * psubcmp;

	while (1) {
		pcmp = p;
		psubcmp = psub;
		isSub = true;
		while (*psubcmp != '\0')
			if (*psubcmp != *pcmp) {
				isSub = false;
				break;
			}
			else {
				psubcmp++;
				pcmp++;
			}
		if (isSub)
			return p - str + 1;
		p++;
		if (*p == '\0')
			return 0;
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return 0;
	const char* p = str + tj_strlen(str);
	p--;
	while (p >= str) {
		if (*p == ch)
			return p - str + 1;
		p--;
	}
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL || substr == NULL)
		return 0;
	bool isSub;
	const char* p = str + tj_strlen(str) - 1, * psub = substr, * pcmp, * psubcmp;
	while (1) {

		pcmp = p;
		psubcmp = psub;
		isSub = true;
		while (*psubcmp != '\0')
			if (*psubcmp != *pcmp) {
				isSub = false;
				break;
			}
			else {
				psubcmp++;
				pcmp++;
			}
		if (isSub)
			return p - str + 1;
		p--;
		if (p == str - 1)
			return 0;
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return NULL;
	char* forward = str, * backward = str + tj_strlen(str) - 1;
	char temp;
	while (forward <= backward) {
		temp = *forward;
		*forward++ = *backward;
		*backward-- = temp;
	}
	return str;
}
