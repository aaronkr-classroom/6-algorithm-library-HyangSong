#include <algorithm> // find_if()
#include <cctype> // isspace()
#include <iostream>
#include <string>
#include <vector>

using namespace std;



// 인수가 공백일 때는 true, 그렇지 않을 때는 false
 bool space(char c) {
	return isspace(c);
}

// 인수가 공백일 때는 false, 그렇지 않을 때는 ture
bool not_space(char c) {
	return !isspace(c);
}

typedef string::size_type str_sz;
typedef string::const_iterator iter;

vector<string> split(const string& s) {
	vector<string> ret;
	iter i = s.begin(); // 요소를 가리키는 포인터

	// 불변성: 지금까지 [원래의 i, 현재의 i) 범위에 있는 
	// 문자열을 처리
	while (i != s.end()) {
		cout << "string begin pos: " <<
			distance(s.begin(), i) << endl;

		// 선행 공백을 무시
		// 지금 i위치부터 첫 번째 띄어쓰기 아닌 문자 찾기
		i = find_if(i, s.end(), not_space);
		cout << "string find pos: " <<
			distance(s.begin(), i) << endl;

		// 다음 단어의 끝을 찾음
		// while 반복할 때 항상 새로운 반복자 j를 생성
		// 지금 i위치부터 첫번째 띄어쓰기 문자 찾기
		iter j = find_if(i, s.end(), space);
		cout << "j pos: " <<
			distance(s.begin(), j) << endl;

		// [i,j) 범위의 문자를 복사
		if (i != s.end()) {
			ret.push_back(string(i, j)); // substr() 인덱스 했을 때
		}
		
		// i 반복자 위치가 j 반복자의 위치를 저장하기 
		i = j;
		cout << "i pos: " <<
			distance(s.begin(), i) << endl;
	}
	return ret;
}

int main() {
	string s;

	// 문자열을 한 행씩 입력받아 분할
	while (getline(cin, s)) {
		vector<string> v = split(s);

		// 벡터 v에 저장한 ㄴ단어를 각각 출력
		for (str_sz i = 0; i != v.size(); i++) {
			cout << v[i] << endl;
		}

	}
	return 0;
}