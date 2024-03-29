/*
동적배열, 임의의 위치에 있는 원소 접근과 뒤에서 원소를 추가하는 연산 O(1) 보장.
array와 다르게 크기 지정 불필요.
2차원 좌표를 나타낼 수 있는 vector<pair<int, int>>의 경우 make_pair(a,b)와 자주 함께쓰임.
*/

int find(vector <string> & words, char c){
	int num= 0;
	for (auto iter = words.begin(); iter!=words.end(); iter++;){
		num += (*iter).begin(), (*iter).end(), c) 
		}
	return num;}