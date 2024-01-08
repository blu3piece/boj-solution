# [Gold II] Feast Coins - 11801 

[문제 링크](https://www.acmicpc.net/problem/11801) 

### 성능 요약

메모리: 2180 KB, 시간: 96 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 배낭 문제, 우선순위 큐

### 제출 일자

2024년 1월 8일 23:08:00

### 문제 설명

<p>Last feast the young princess received way too many coins. Since she is very young, she doesn’t know the value of each coin, if you give her a coin with the value 5 or a coin with the value 1, she will consider them both as just 1 coin, regardless of the value.</p>

<p>However, she can notice that the coin with value 5 doesn’t look the same as the coin with value 1, and she will be happy if she has the same number of coins of each value. Otherwise, she will not be happy.</p>

<p>She has a lot of coins of different values, and she needs some subset of these coins such that the sum of their values should be exactly S, and the number of coins of each value in this subset should be the same. Can you help her to count the number of different ways to do this?</p>

### 입력 

 <p>Your program will be tested on one or more test cases. The first line of the input will be a single integer T (1 ≤ T ≤ 100) representing the number of test cases. Followed by T test cases. Each test case starts with a line containing two integers separated by a single space S and N (1 ≤ S ≤ 5,000) (1 ≤ N ≤ 50) representing the total required sum and the number of different values of coins, respectively. Followed by N lines, each one will contain two integers separated by a single space V<sub>i</sub> and C<sub>i</sub> (1 ≤ V<sub>i</sub>, C<sub>i</sub> ≤ 5,000) representing the value of a coin and the number of coins the princess has with this value, respectively. For each test case, all values of V<sub>i</sub> will be distinct.</p>

### 출력 

 <p>For each test case print a single line containing “Case n:” (without quotes) where n is the test case number (starting from 1) followed by a space then the number of different ways to make the total sum S as described above. Two ways are considered different if any coin value does not appear the same number of times in both ways.</p>

<p>You can assume that the result will always fit in a 64-bit signed integer.</p>

