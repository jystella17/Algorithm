// BOJ 20327 배열 돌리기 6 (G2)
// 케이스 구분 및 빠른 규칙 찾기 필요
// 2차원 배열 회전을 위해 추가 배열 필요

import java.io.*;
import java.util.*;

public class Main {
    
    static int[][] array;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int length = (int) Math.pow(2, n);
        array = new int[length][length];
        
        for (int i=0; i<length; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<length; j++) {
                array[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        for (int c=0; c<r; c++) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            
            int multi = (int) Math.pow(2, n-l) - 1;
            int level = (int) Math.pow(2, l);
            
            if (k < 5) {
                for (int i=0; i<=multi; i++) {
                    for (int j=0; j<=multi; j++) {
                        partial(level*i, level*j, level*(i+1) - 1, level*(j+1) - 1, k);
                    }
                }
            } else {
                if (k == 5) {
                    int low = 0, high = multi;
                    while (low < high) {
                        for (int i=0; i<level; i++) {
                            int[] tmp = array[level*low + i];
                            array[level*low + i] = array[level*high + i];
                            array[level*high + i] = tmp;
                        }
                        low++; high--;
                    }
                } else if (k == 6) {
                    int low = 0, high = multi;
                    while (low < high) {
                        for (int i=0; i<length; i++) {
                            for (int j=0; j<level; j++) {
                                int tmp = array[i][level*low + j];
                                array[i][level*low + j] = array[i][level*high + j];
                                array[i][level*high + j] = tmp;
                            }
                        }
                        low++; high--;
                    }
                } else if (k == 7) {
                    int[][] copy = new int[length][length];
                    for (int i=0; i<length; i++) {
                        for (int j=0; j<length; j++) {
                            copy[i][j] = array[i][j];
                        }
                    }

                    for (int i=0; i<=multi; i++) {
                        for (int j=0; j<=multi; j++) {
                            for (int p=0; p<level; p++) {
                                for (int q=0; q<level; q++) {
                                    copy[level*j + p][level * (multi-i) + q] = array[level*i + p][level*j + q];
                                }
                            }
                        }
                    }

                    for (int i=0; i<length; i++) {
                        for (int j=0; j<length; j++) {
                            array[i][j] = copy[i][j];
                        }
                    }
                } else if (k == 8) {
                    int[][] copy = new int[length][length];
                    for (int i=0; i<length; i++) {
                        for (int j=0; j<length; j++) {
                            copy[i][j] = array[i][j];
                        }
                    }

                    for (int i=0; i<=multi; i++) {
                        for (int j=0; j<=multi; j++) {
                            for (int p=0; p<level; p++) {
                                for (int q=0; q<level; q++) {
                                    copy[level * (multi-j) + p][level*i + q] = array[level*i + p][level*j + q];
                                }
                            }
                        }
                    }

                    for (int i=0; i<length; i++) {
                        for (int j=0; j<length; j++) {
                            array[i][j] = copy[i][j];
                        }
                    }
                }
            }
        }
        for (int i=0; i<length; i++) {
            for (int j=0; j<length; j++) {
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    static void partial(int startX, int startY, int endX, int endY, int type) {
        if (type == 1) {
            int low = startX, high = endX;
            while (low < high) {
                for (int j=startY; j<=endY; j++) {
                    int tmp = array[low][j];
                    array[low][j] = array[high][j];
                    array[high][j] = tmp;
                }
                low++; high--;
            }
        } else if (type == 2) {
            int low = startY, high = endY;
            while (low < high) {
                for (int i=startX; i<=endX; i++) {
                    int tmp = array[i][low];
                    array[i][low] = array[i][high];
                    array[i][high] = tmp;
                }
                low++; high--;
            }
        } else if (type == 3) {
            int[][] copy = new int[endX - startX + 1][endY - startY + 1];
            for (int i=startX; i<=endX; i++) {
                for (int j=startY; j<=endY; j++) {
                    copy[i - startX][j - startY] = array[i][j];
                }
            }

            for (int i=startX; i<=endX; i++) {
                for (int j=startY; j<=endY; j++) {
                    array[i][j] = copy[endY - j][i - startX];
                }
            }
        } else if (type == 4) {
            int[][] copy = new int[endX - startX + 1][endY - startY + 1];
            for (int i=startX; i<=endX; i++) {
                for (int j=startY; j<=endY; j++) {
                    copy[i - startX][j - startY] = array[i][j];
                }
            }

            for (int i=startX; i<=endX; i++) {
                for (int j=startY; j<=endY; j++) {
                    array[i][j] = copy[j - startY][endX - i];
                }
            }
        }
    }
}
