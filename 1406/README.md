# 1406 - 에디터

영어 소문자 문자열을 편집하는 에디터를 구현한다.

'커서'는 문장 맨 앞, 문장 맨 뒤, 또는 문장 중간 임의의 곳에 위치할 수 있다.
즉 길이가 L인 문자열에서 커서가 위치할 수 있는 곳은 L+1개이다.

편집기에서 지원하는 명령어는 다음과 같다.

L -> 커서를 왼쪽으로 한 칸 옮김(커서가 문장 맨 앞이면 무시)
D -> 커서를 오른쪽으로 한 칸 옮김(커서가 문장 맨 뒤면 무시)
B -> 커서 왼쪽의 문자 삭제(커서가 문장 맨 앞이면 무시) -> 삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
P $ -> $라는 문자를 커서 왼쪽에 추가

**입력**

첫 줄에는 초기 편집기에 입력된 문자열이 주어진다. (<=100,000)
둘째 줄에는 입력할 명령어의 개수(1<=M<=500,000)가 주어진다.
셋째 줄부터 M개의 줄에 걸쳐 명령어가 주어진다.

**출력**

모든 명령어를 수행하고 난 후의 문자열을 출력한다.