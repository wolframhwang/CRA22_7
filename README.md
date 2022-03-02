# Commit Message Rule

Git Commit 메세지 룰을 가능하면 지켜봅시다~

<br>

## 기본 형식

```
type(타입) : title(제목)

- body(본문, 생략 가능)
```

<br>

## 타입 종류

[Angular 의 Git Commit Guidelines](https://github.com/angular/angular.js/blob/master/DEVELOPERS.md#-git-commit-guidelines) 참고

```
feat : 새로운 기능에 대한 커밋
fix : 버그 수정에 대한 커밋
docs : 문서 수정에 대한 커밋
style : 코드 스타일 혹은 포맷 등에 관한 커밋
refactor :  코드 리팩토링에 대한 커밋
perf: 성능 향상을 위한 코드 개선
test : 테스트 코드에 대한 커밋
chore : 빌드 관련 파일 수정에 대한 커밋 (적용 안되는것 같음 사용x)
```

<br>

## Example

```
feat: User 가입 기능 추가

- RequestUserDto 추가
- User Entity 추가
```

```
docs: README 에 Swagger URL 추가
```

```
chore: User 변수명 Users 로 수정
```


<br>

## Reference
- [[Git] Commit message 작성 규칙](https://velog.io/@djh20/Git-%EC%A0%9C%EB%8C%80%EB%A1%9C-%EC%82%AC%EC%9A%A9%ED%95%B4%EB%B3%B4%EC%9E%90)
- [좋은 git commit 메시지를 위한 영어 사전](https://blog.ull.im/engineering/2019/03/10/logs-on-git.html)