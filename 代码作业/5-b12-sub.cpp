/*2152402 Èí¼ş ¶ÎæÃæÃ*/
#include<iostream>
#include "5-b12.h"
using namespace std;

int tj_strlen(const char str[])
{
	int len = 0;
	while (str[len] != '\0')
		++len;
	return len;
}
int tj_strcat(char s1[], const char s2[])
{
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	for (int i = len1;i <= len1 + len2;++i)
		s1[i] = s2[i - len1];
	return 0;
}
int tj_strncat(char s1[], const char s2[], const int len)
{
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	int n = min(len, len2);
	for (int i = len1;i < len1 + n;++i)
		s1[i] = s2[i - len1];
	s1[len1 + n] = '\0';
	return 0;
}
int tj_strcpy(char s1[], const char s2[])
{
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	for (int i = 0;i <= len2;++i)
		s1[i] = s2[i];
	return 0;
}
int tj_strncpy(char s1[], const char s2[], const int len)
{
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	int n = min(len, len2);
	for (int i = 0;i < n;++i)
		s1[i] = s2[i];
	return 0;
}
int tj_strcmp(const char s1[], const char s2[])
{
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	int minlen = min(len1, len2);
	for (int i = 0;i < minlen;++i)
		if (s1[i] > s2[i] || s2[i] > s1[i])
			return s1[i] - s2[i];
	return s1[minlen] - s2[minlen];
}
int charlwr(const char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;
	return c;
}
int tj_strcasecmp(const char s1[], const char s2[])
{
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	int minlen = min(len1, len2);
	for (int i = 0;i < minlen;++i)
		if (charlwr(s1[i]) > charlwr(s2[i]) || charlwr(s2[i]) > charlwr(s1[i]))
			return charlwr(s1[i]) - charlwr(s2[i]);
	return charlwr(s1[minlen]) - charlwr(s2[minlen]);
}
int tj_strncmp(const char s1[], const char s2[], const int len)
{
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	int n = min(len, min(len1, len2));
	for (int i = 0;i < n;++i)
		if (s1[i] > s2[i] || s2[i] > s1[i])
			return s1[i] - s2[i];
	if (len <= len1 && len <= len2)
		return 0;
	return s1[n] - s2[n];
}
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
	int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
	int n = min(len, min(len1, len2));
	for (int i = 0;i < n;++i)
		if (charlwr(s1[i]) > charlwr(s2[i]) || charlwr(s2[i]) > charlwr(s1[i]))
			return charlwr(s1[i]) - charlwr(s2[i]);
	if (len <= len1 && len <= len2)
		return 0;
	return charlwr(s1[n]) - charlwr(s2[n]);
}
int tj_strupr(char str[])
{
	int len = tj_strlen(str);
	for (int i = 0;i < len;++i)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	return 0;
}
int tj_strlwr(char str[])
{
	int len = tj_strlen(str);
	for (int i = 0;i < len;++i)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	return 0;
}
int tj_strchr(const char str[], const char ch)
{
	int len = tj_strlen(str);
	for (int i = 1;i <= len;++i)
		if (str[i - 1] == ch)
			return i;
	return 0;
}
int tj_strstr(const char str[], const char substr[])
{
	int len1 = tj_strlen(str), len2 = tj_strlen(substr);
	for (int i = 0;i <= len1 - len2;++i)
	{
		bool tag = 1;
		for (int j = 0;j < len2;++j)
		{
			if (str[i + j] != substr[j])
			{
				tag = 0;
				break;
			}
		}
		if (tag)
			return i + 1;
	}
	return 0;
}
int tj_strrchr(const char str[], const char ch)
{
	int len = tj_strlen(str);
	for (int i = len;i > 0;--i)
		if (str[i - 1] == ch)
			return i;
	return 0;
}
int tj_strrstr(const char str[], const char substr[])
{
	int len1 = tj_strlen(str), len2 = tj_strlen(substr);
	for (int i = len1 - len2;i >= 0;--i)
	{
		bool tag = 1;
		for (int j = 0;j < len2;++j)
		{
			if (str[i + j] != substr[j])
			{
				tag = 0;
				break;
			}
		}
		if (tag)
			return i + 1;
	}
	return 0;
}
int tj_strrev(char str[])
{
	int len = tj_strlen(str);
	for (int i = 0;i < len / 2;++i)
	{
		char t = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = t;
	}
	return 0;
}