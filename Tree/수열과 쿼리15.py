import sys
input = sys.stdin.readline
VALUE, INDEX = 0, 1

def initialize_seg_tree(index, left, right):
  if(left == right):
    seg_tree[index] = [nums[left],left]     
  else:
    mid = (left + right) // 2
    initialize_seg_tree(index*2, left, mid)
    initialize_seg_tree(index*2+1, mid+1, right)

    smaller_index = index*2
    if(seg_tree[index*2][VALUE] > seg_tree[index*2+1][VALUE]):
      smaller_index = index*2+1

    seg_tree[index] = [seg_tree[smaller_index][VALUE],seg_tree[smaller_index][INDEX]]   

def update_seg_tree(index, left, right, start, end, value):
  if(right < start or end < left):
    return
  if(left == right):
    seg_tree[index] = [value, left]
    return

  mid = (left + right) // 2
  update_seg_tree(index*2, left, mid, start, end, value)
  update_seg_tree(index*2+1, mid+1, right, start, end, value)

  smaller_index = index*2     
  if(seg_tree[index*2][VALUE] > seg_tree[index*2+1][VALUE]):
    smaller_index = index*2+1
                            
  seg_tree[index] = [seg_tree[smaller_index][VALUE],seg_tree[smaller_index][INDEX]] 


if __name__ == '__main__':
  N = int(input())
  nums = [0] + list(map(int, input().split()))

  seg_tree = [[0,0]]*(4*N) # value, index
  initialize_seg_tree(1, 1, N)      

  M = int(input())
  for _ in range(M):
    order = list(map(int, input().split()))
    if(order[0] == 1):
      update_seg_tree(1, 1, N, order[1], order[1], order[2])
    else:
      print(seg_tree[1][INDEX])
