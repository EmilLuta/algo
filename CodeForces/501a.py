def go():
    m_p, v_p, m_t, v_t = [int(i) for i in input().split(' ')]
    v = max(3 * v_p // 10, v_p - v_p // 250 * v_t)
    m = max(3 * m_p // 10, m_p - m_p // 250 * m_t)
    if m > v:
        return 'Misha'
    if v > m:
        return 'Vasya'
    return 'Tie'

print(go())
