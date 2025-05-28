def method_bord(chains):
    scores = {c: 0 for c in chains[0]}

    for chain in chains:
        for i in range(len(chain)):
            scores[chain[i]] += len(chain) - 1 - i

    max = -1
    max_key = ' '
    for candidate, score in scores.items():
        if score > max:
            max = score
            max_key = candidate
    return max_key

def method_condorse(chains):
    scores = {c: 0 for c in chains[0]}

    for chain in chains:
        scores[chain[0]] += 1

    max_votes = -1
    winner = ' '
    for candidate, votes in scores.items():
        if votes > max_votes:
            max_votes = votes
            winner = candidate
    return winner

n, k = map(int, input().split())
chains = []
for i in range(k):
    print(f"Цепь для {i+1} избирателя:")
    chains.append(input().split())

print(f"По методу Борда выигрывает кандидат {method_bord(chains)}")
print(f"По методу Кондорсе выигрывает кандидат {method_condorse(chains)}")