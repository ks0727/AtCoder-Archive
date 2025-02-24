from collections import deque
def main():
    s = list(input())
    dic = {}
    dic['('] = 1
    dic[')'] = -1
    dic['['] = 2
    dic[']'] = -2
    dic['<'] = 3
    dic['>'] = -3
    
    st = deque([])
    for c in s:
        if len(st) == 0 or dic[c] > 0:
            st.append(dic[c])
        else:
            tp = st.pop()
            if tp == -dic[c]:
                continue
            else:
                st.append(tp)
                st.append(dic[c])
    
    if len(st) == 0:
        print("Yes")
    else:
        print("No")
    

if __name__ == "__main__":
    main()