def solution(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        answer = answer + possible(skill, skill_tree)
    return answer

def possible(skill, skill_tree):
    for i in range(len(skill) - 1):
        if skill_tree.find(skill[i]) > skill_tree.find(skill[i + 1]):
            if skill_tree.find(skill[i + 1]) == -1:
                continue
                
            else: 
                return False
            
        if (skill_tree.find(skill[i]) == -1) & (skill_tree.find(skill[i + 1]) != -1):
            return False
        
    return True
