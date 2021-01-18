# C-Algorithm

### 프로젝트 오류 수정

1. C6031
   - 프로젝트 - 속성 - C/C++ - 고급 - 특정 경고 사용 안함 - 6031
2. C4996
   - 프로젝트 - 속성 - C/C++ - 전처리기 - 전처리기 정의 - <편집...> - `_CRT_SECURE_NO_WARNINGS`

### input 받기

1. 소스 파일에 `input.txt` 추가
2. `freopen("input.txt", "r", stdin);`