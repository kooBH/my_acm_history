def solution(genres, plays):
    g_cnt = {}
    gg = {}

    # Most played genres
    for i in range(len(genres))  :
        if (genres[i] in g_cnt ) : 
            g_cnt[genres[i]]=g_cnt[genres[i]]+plays[i]             
            gg[genres[i]].append(i)
        else :
            g_cnt[genres[i]]=plays[i]
            gg[genres[i]]=[i]

    # Sort genres in descending order 
    g_cnt = sorted(g_cnt.items(),key=lambda x:x[1],reverse=True)
    
    # Sort songs in genres in descending order
    for k in gg :
        gg[k] = sorted(gg[k],key = lambda x:plays[x],reverse=True)

    # 2 Most played in a genres
    answer = []
    for i in g_cnt:
        answer.append(gg[i[0]][0])
        if(len(gg[i[0]]) > 1):
            answer.append(gg[i[0]][1])

    return answer


g = ["classic", "classic","pop", "classic", "classic", "pop",'pork']
p = [500, 500,600, 150, 800, 2500,50]

print(solution(g,p))