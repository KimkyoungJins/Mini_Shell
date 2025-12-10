# 최종 실행 파일 이름
TARGET = myshell

# 소스 파일 목록
SRCS = main.c eval.c builtin.c parseline.c

# 객체 파일 목록 (소스 파일에서 .c만 .o로 변경)
OBJS = $(SRCS:.c=.o)

# 컴파일러 설정
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# 1. 최종 실행 파일 생성 규칙 (myshell)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# 2. 객체 파일 생성 규칙 (각 .c 파일을 .o 파일로 컴파일)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 3. 정리 규칙
clean:
	rm -f $(OBJS) $(TARGET)

# 4. 모든 소스 파일이 .o 파일에 의존함을 명시
all: $(TARGET)
