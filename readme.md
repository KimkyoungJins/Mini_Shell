bash shell을 흉내낸 mini shell을 만들어서 다음 기능들을 가능하게 하면 추가 점수 부여 (최대로 과제 1회에 해당하는 점수)

마감은 15주차 목요일 23시 50분까지 온라인 제출 후 개인별 "구술시험"으로 평가함

 

주의: 생성형 AI를 이용해서만들어진 코드를 그대로 사용하면 안됨. 

 

fork, execv 등 system call을 이용해서 구현하면 됨. ^Z입력시 또는 ^C 입력시 shell이 죽거나 background가 되면 안됨. 

* prompt는 % 로 함

* 명령어 설명에서 [와 ] 사이의 내용은 생략 가능한 옵션이다는 의미임.

 

% ls [-a] [-l] [-F] 

% cd  [path]

% pwd

% exit

% logout

% date

% cat file_name [file2_name] ...

% cp  src_file_name  dest_file_name

% cp [-r] src_file_name  dest_dir_name

% rm  file_name

% rm [-r] dir_name

% rmdir  dir_name

% mv  src_file_name  dest_file_name

% mv  src_dir_name dest_dir_name

% mv  src file_name dest_dir_name

% mkdir  dir_name

 

위에 열거된 모든 명령어는 리눅스의 원래 명령어와 동일하게 작동해야 함.

cd 명령어에 인자가 없으면 처음 로그인한위치 ( $HOME) 으로 현재디렉토리가 변경되어야 함.

단, 다음의 새로운 커맨드를 추가해야 함.

 

% DIR path

-> (cd path ; ls -l) 을 실행한 효과. 단  ls -ㅣ 명령어와는 출력 포맷이 다음과 같아야 함. 각 필드 간에는 빈칸 2개가 와야 함.

화일타입(d:directory ; f: file;  l: symbolic link; - : 기타)  화일크기 (바이트)  화일의 마지막 수정날짜 (년-월-일-시-분) 화일권한(8진수로)  화일이름

% CD [path]
