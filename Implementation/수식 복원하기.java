// PCCP 기출문제 4번 수식 복원하기 (Lv.3)

import java.util.*;

class Solution {
    public String[] solution(String[] expressions) {
        String[] answer = {};
        List<String> result = new ArrayList<>(Arrays.asList(answer));
        
        int minimum = 1;
        for(int i=0; i<expressions.length; i++) {
            String[] expression = expressions[i].split(" ");
            int x = Integer.parseInt(expression[0]);
            int y = Integer.parseInt(expression[2]);
            int z = 0;
            if(expression[4].charAt(0) != 'X') 
                z = Integer.parseInt(expression[4]);

            // 어떤 숫자가 n진법으로 표현되어 있다면, 해당 숫자의 모든 자리수는 n 미만
            // (2진법은 0~1, 3진법은 0~2, 4진법은 0~3 , ... , 10진법은 0~9 사이의 숫자로 구성)
            // ex. 51은 6~9진법으로만 표현 가능한 숫자
            // 따라서, 주어진 수식에 포함된 모든 숫자(자리수) 중 가장 큰 값 + 1 = 수식 표현에 사용할 수 있는 진법의 최소값
            if(x < 10) minimum = Math.max(minimum, x);
            if(x < 100) minimum = Math.max(minimum, x / 10);
            minimum = Math.max(minimum, x / 100);
            
            if(y < 10) minimum = Math.max(minimum, y);
            if(y < 100) minimum = Math.max(minimum, y / 10);
            minimum = Math.max(minimum, y / 100);
            
            if(z < 10) minimum = Math.max(minimum, z);
            if(z < 100) minimum = Math.max(minimum, z / 10);
            minimum = Math.max(minimum, z / 100);
        }

        // 사용할 수 있는 진법의 최소값이 9인 경우, minimum + 1을 했을 때 10이 되므로 (문제에서 주어진 조건 위배) 최대를 9로 제한
        minimum = Math.min(minimum+1, 9);
        List<Integer> candidate = new ArrayList<>();

        // minimum ~ 9진법까지 각 진법으로 수식을 표현할 수 있는지 확인
        for(int i=minimum; i<=9; i++) {
            boolean thisForm = true;
            
            for(int j=0; j<expressions.length; j++) {
                String[] expression = expressions[j].split(" ");
                if(expression[4].charAt(0) == 'X') continue; // 수식 결과값이 X => 진법 여부 판단에 사용할 수 없는 수식
                
                int x = Integer.parseInt(expression[0]);
                int y = Integer.parseInt(expression[2]);
                int z = Integer.parseInt(expression[4]);
                char exp = expression[1].charAt(0);

                // i진법으로 표현할 수 없는 수식이 하나라도 있다면, 더 이상 탐색하지 않고 다음 진법으로 넘어감
                if(!canCalculate(i, x, y, z, exp)) {
                    thisForm = false;
                    break;
                }
            }

            // 주어진 모든 수식을 i진법으로 표현할 수 있다면, 진법 후보에 추가
            if(thisForm) {
                candidate.add(i);
            }
        }

        // 결과값이 X로 표현된 수식의 실제 결과값 구하기
        for(int j=0; j<expressions.length; j++) {
            String[] expression = expressions[j].split(" ");
            if(expression[4].charAt(0) != 'X') continue;
                
            int x = Integer.parseInt(expression[0]);
            int y = Integer.parseInt(expression[2]);
            char exp = expression[1].charAt(0);
            
            int calcRes = 0;
            for(int n : candidate) {
                // 첫 번째 후보를 탐색중인 경우, 연산 결과값 단순 저장
                if(calcRes == 0) calcRes = calculate(n, x, y, exp);

                // 진법 후보가 2개 이상 존재하고, 이미 탐색된 후보가 있으면서, 이미 탐색된 후보(진법)을 적용한 결과값이 현재 결과값과 다른 경우 
                // => 결과값이 ? 으로 기록되어야 하는 케이스 (calcRes == -1)
                else if(calcRes != 0 && calcRes != calculate(n, x, y, exp)) {
                    calcRes = -1;
                    break;
                }
            }

            // 모든 후보 진법에 대해 동일한 결과값을 갖는 수식인 경우
            if(calcRes >= 0) {
                String equation = x + " " + exp + " " + y + " = " + calcRes;
                result.add(equation);
            }

            // 후보 진법에 따라 다른 결과값을 갖는 수식인 경우
            else {
                String equation = x + " " + exp + " " + y + " = ?";
                result.add(equation);
            }
        }
        
        answer = result.toArray(answer);
        return answer;
    }
    
    public static boolean canCalculate(int n, int x, int y, int z, char exp) {
        int decX = (n * n * (x / 100)) + (n * ((x % 100) / 10)) + (x % 10);
        int decY = (n * n * (y / 100)) + (n * ((y % 100) / 10)) + (y % 10);
        int decZ = (n * n * (z / 100)) + (n * ((z % 100) / 10)) + (z % 10);
        
        if(exp == '+') {
            if(decX + decY == decZ) return true;
        }
        
        else {
            if(decX - decY == decZ) return true;
        }
        
        return false;
    }
    
    public static int calculate(int n, int x, int y, char exp) {
        int decX = (n * n * (x / 100)) + (n * ((x % 100) / 10)) + (x % 10);
        int decY = (n * n * (y / 100)) + (n * ((y % 100) / 10)) + (y % 10);
        int decZ = 0;
        
        if(exp == '+') decZ = (decX + decY);
        else decZ = (decX - decY);

        // 10진법을 기준으로 결과값을 계산한 후, 다시 n진법으로 변환
        int result = 0;
        result += (decZ / (n*n)) * 100;
        result += ((decZ % (n*n)) / n) * 10;
        result += (decZ % n);
        
        return result;
    }
}
