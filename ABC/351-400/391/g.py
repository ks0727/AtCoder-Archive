import heapq

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    N = int(data[idx])
    idx += 1
    K = int(data[idx])
    idx +=1
    
    A = list(map(int, data[idx:idx+N]))
    idx += N
    B = list(map(int, data[idx:idx+N]))
    idx += N
    C = list(map(int, data[idx:idx+N]))
    idx += N
    
    A.sort(reverse=True)
    C.sort(reverse=True)
    B_max = max(B)
    B_min = min(B)
    
    visited = set()
    heap = []
    
    # 各i,kのmax_valを計算し、最大ヒープとして管理するために符号を反転
    def compute_max_val(i, k):
        a = A[i]
        c = C[k]
        s = a + c
        val1 = s * (B_max + c) - c**2
        val2 = s * (B_min + c) - c**2
        return -max(val1, val2)  # 最小ヒープを最大ヒープとして使用するため
    
    # 初期状態 (0,0) を追加
    initial_val = compute_max_val(0, 0)
    heapq.heappush(heap, (initial_val, 0, 0))
    visited.add((0, 0))
    
    result = None
    count = 0
    
    while heap and count < K:
        current_val, i, k = heapq.heappop(heap)
        result = -current_val
        count += 1
        if count == K:
            break
        
        # 次のi+1,kをチェック
        if i + 1 < N and (i+1, k) not in visited:
            val = compute_max_val(i+1, k)
            heapq.heappush(heap, (val, i+1, k))
            visited.add((i+1, k))
        
        # 次のi,k+1をチェック
        if k + 1 < N and (i, k+1) not in visited:
            val = compute_max_val(i, k+1)
            heapq.heappush(heap, (val, i, k+1))
            visited.add((i, k+1))
    
    print(result)

if __name__ == "__main__":
    main()