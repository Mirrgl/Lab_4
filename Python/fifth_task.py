import random
import time

def always_coop(round_number, self_choices, enemy_choices):
    return 1 

def mirror(round_number, self_choices, enemy_choices):
    if round_number == 0:
        return 1
    return enemy_choices[round_num-1]

def reverse(round_number, self_choices, enemy_choices):
    if round_number == 0:
        return 1
    return (self_choices[round_num-1] + 1) % 2

def score_count(a_score, b_score, a_choice, b_choice):
    if a_choice == 0 and b_choice == 0:
        return a_score + 4, b_score + 4
    elif a_choice == 1 and b_choice == 1:
        return a_score + 24, b_score + 24
    elif a_choice == 1 and b_choice == 0:
        return a_score, b_score + 20
    elif a_choice == 0 and b_choice == 1:
        return a_score + 20, b_score


random.seed(time.time())
max_round = random.randint(100, 200)
    
print("Всегда сотрудничество")
a_score, b_score = 0, 0
a_choices, b_choices = [], []
for round_num in range(max_round + 1):  
    a_choice = always_coop(round_num, a_choices, b_choices)
    b_choice = always_coop(round_num, b_choices, a_choices)
    a_choices.append(a_choice)
    b_choices.append(b_choice)
    a_score, b_score = score_count(a_score, b_score, a_choice, b_choice)
print(f"A: {a_score}\nB: {b_score}\n")

print("Зеркальное против обратного")
a_score, b_score = 0, 0
a_choices, b_choices = [], []
for round_num in range(max_round + 1):
    a_choice = mirror(round_num, a_choices, b_choices)
    b_choice = reverse(round_num, b_choices, a_choices)
    a_choices.append(a_choice)
    b_choices.append(b_choice)
    a_score, b_score = score_count(a_score, b_score, a_choice, b_choice)
print(f"A: {a_score}\nB: {b_score}\n")

print("Сотрудничество против обратного")
a_score, b_score = 0, 0
a_choices, b_choices = [], []
for round_num in range(max_round + 1):
    a_choice = always_coop(round_num, a_choices, b_choices)
    b_choice = reverse(round_num, b_choices, a_choices)
    a_choices.append(a_choice)
    b_choices.append(b_choice)
    a_score, b_score = score_count(a_score, b_score, a_choice, b_choice)
print(f"A: {a_score}\nB: {b_score}")