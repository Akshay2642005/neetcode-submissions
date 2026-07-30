func checkInclusion(s1 string, s2 string) bool {
    count1 := make(map[rune]int)
    for _, c := range s1 {
        count1[c]++
    }
    need := len(count1)
    for i := 0; i < len(s2); i++ {
        count2 := make(map[rune]int)
        cur := 0
        for j := i; j < len(s2); j++ {
            count2[rune(s2[j])]++
            if count1[rune(s2[j])] < count2[rune(s2[j])] {
                break
            }
            if count1[rune(s2[j])] == count2[rune(s2[j])] {
                cur++
            }
            if cur == need {
                return true
            }
        }
    }
    return false
}
