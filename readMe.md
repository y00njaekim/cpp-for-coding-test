## 목차

[Chapter9. 최단 경로](#chapter9.-최단-경로)

[Chapter10. 그래프](#chapter10.-그래프)

#### 알고리즘 유형별 기출문제

[Chapter11. 그리디문제](#chapter11.-그리디문제)

---

#### Chapter9. 최단 경로

- 전보

  ✔️   ToDoList

  - `visited[]` 쓰지 말고 갱신 가능성을 바탕으로 방문 여부 판단하기 [코드설명](https://y00njaekim.github.io/algorithm/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/#%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0%EC%97%90-%EC%A1%B0%EA%B8%88-%EB%8D%94-%EA%B9%8C%EB%8B%A4%EB%A1%AD%EC%A7%80%EB%A7%8C-%EB%B9%A0%EB%A5%B4%EA%B2%8C-%EB%8F%99%EC%9E%91%ED%95%98%EB%8A%94-%EC%BD%94%EB%93%9C) 참조

<br/>

#### Chapter10. 그래프

- 크루스칼

  📌  Remember

  - 간선 리스트 변수 명 `edges`

  - `node` 사이의 거리에 대한 변수 명 `cost`

  - property 가 세개 이상인 자료 구조의 경우 구조체와 `compare` function 을 만들어서 `sort` 할 수 있지만 `pair<int, pair<int, int> >` 와 같이 pair 을 중첩해서 사용할 수도 있음을 기억!

  - `parent[]` 는 `findParent()` 를 위한 수단일 뿐

    - `if(findParent(graph[i].second.first) == findParent(graph[i].second.second)) continue;`  에서 `findParent()` 대신 `parent[]` 를 참조하는 식의 방법은 틀림!

- 커리큘럼

  📌  Remember

  - next node 를 check 할 때 시간비용 갱신하면 `graphIn` , `graphOut` 구분할 필요 없음

    - ```cpp
      int nextSize = graphOut[cur].size();
      for(int j=0; j<nextSize; j++) {
       // 여기서 갱신!! 
      }
      ```

  ✔️   ToDoList

  - `prevSize`, `graphIn` 따로 만들지 말고 문제 풀기
  
---

#### Chapter11. 그리디문제

- 모험가 길드

  📌  Remember

  - `priority_queue` 는 내림차순 정렬임을 기억!
  - `while` 문의 조건문과 탈출문을 헷갈리지 말자
    - `while(inGuild != maxGuild && !q.empty()) {` 에서 `&&` 과 `||` 중 당연히 `&&` 을 했어야 했는데.

  ✔️   ToDoList

  - 다음에는 `queue` 말고 `vector` 이용하기
    - `while` 문의 조건으로 이용하는 `queue.empty()` 와 `for` 문을 이용한 `vector` 의 순회는 둘 다 끝이 있다는 점에서 동일


- 만들 수 없는 금액

  ❓ Question

  - 이게 왜 그리디 알고리즘으로 분류되는 걸까.


- [무지의 먹방 라이브](https://github.com/y00njaekim/cpp-for-coding-test/blob/master/ch11_greedy/eating_show.md)

---

#### chapter12. 구현

- 자물쇠와 열쇠

  📌  Remember

  - `vector` 초기화 방법

    1. 5X5 Matrix 만들기: `vector<vector<int> > result(5, vector<int>(5))`
    2. 0으로 초기화된 5X5 Matrix 만들기: `vector<vector<int> > result(5, vector<int>(5, 0))`

  - Matrix 90도 회전 방법: 1. transpose 2. 행기준 뒤집기

    ```cpp
    for(int r=0; r<행길이; r++) {
        for(int c=0; c<열길이; c++) {
            res[c][열길이-1-r] = v[r][c]; // r, c -> c, r -> c, vSize-1-r
        }
    }
    ```

- 뱀

  📌  Remember

  - 손으로 미리 구조를 다 짠 후에 코딩을 시작해야 할 듯

    ```cpp
    if(dir.front().first == t) {
      if(dir.front().second == 'L') {
        d--;
        if(d < 0) d += 4; 
      }
      else if(dir.front().second == 'D') {
        d++;
        d = d % 4;
      }
      dir.pop();
    }
    
    next = make_pair(cur.first+dr[d], cur.second+dc[d]);
    ```

    이렇게 짜야하는 걸 (`d` 갱신 이후 `next` 갱신에서 `d` 사용)

    ```cpp
    next = make_pair(cur.first+dr[d], cur.second+dc[d]);
    
    if(dir.front().first == t) {
      if(dir.front().second == 'L') {
        d--;
        if(d < 0) d += 4; 
      }
      else if(dir.front().second == 'D') {
        d++;
        d = d % 4;
      }
      dir.pop();
    }
    ```

    이렇게 짜버렸다. (`d` 갱신 하기도 전에 `next` 갱신에서 `d` 사용)

    잘 안보였다. 디버깅이 힘들었다. 해결 방법으로 생각나는게 손으로 먼저 짜기 시작하지 말고 머리로 구상을 다 한 후에 짜는 게 어떨까 싶다.

  - `-1 % 4` 값은 `-1` 이다..
  
- 기둥과 보 설치

  📌  Remember

  - 복붙할 때 내가 그 코드 왜 썼는지 생각하고 완전하게 같은 상황이 아니라면 해당 코드 수정하기
  - 벽 등의 구조물을 배열로 구현할 때, `segmentation fault` 유의하기
    - `if` 문과 `continue` 잘 이용하기
    - 배열 크기 가로 세로 세 배 해서 가운데 배열만 이용하기
