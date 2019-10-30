queue <int> pos_word(char *str)
{
	int str_length = str.length();
	int i=0;
	int length=0;
	queue<int> result;
	if(str==NULL)return result;
	while ( i<str_length )
	{
		int begin;
		if ( str[i] <= 'z' && str[i] >= 'a' )
		{
			length++;
			if ( length==4 )
			{
				//½«begin´«Èë
				begin=i-3;
				result.push(begin);
			}
		} 
		else 
		{
			length=0;
		}
		i++;
	}
	return result;
}
