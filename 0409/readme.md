파일 열기: open()
파일을 사용하기 위해서는 먼저 open() 시스템 호출을 이용하여 파일을 열어야 한다.

파일 생성: creat()
path가 나타내는 파일을 생성하고 쓰기 전용으로 연다.

파일 닫기: close()
int close( int fd );
fd가 나타내는 파일을 닫는다.

데이터 읽기: read()
ssize_t read ( int fd, void *buf, size_t nbytes );
fd가 나타내는 파일에서 nbytes 만큼의 데이터를 읽고 읽은 데이터는 buf에 저장한다.

데이터 쓰기: write()
ssize_t write (int fd, void *buf, size_t nbytes)
buf에 있는 nbytes 만큼의 데이터를 fd가 나타내는 파일에 쓴다.

파일 위치 포인터 :
파일 위치 포인터는 파일 내에 읽거나 쓸 위치인 현재 파일 위치를 가리킨다.

파일 위치 포인터 이동: lseek()
임의의 위치로 파일 위치 포인터를 이동시킬 수 있다.
EX) lseek(fd, 0L, SEEK_SET);  //파일 시작으로 이동
    lseek(fd, 100L, SEEK_SET); //파일 시작에서 100바이트 위치로 이동
    lseek(fd, 0L, SEEK_END); //파일 끝으로 이동
    
    student.h
    dbcreate.c
    dbquery.c
    dbupdate.c
    암기
