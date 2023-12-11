from fractions import Fraction
def solution(m):
    def gcd(a, b):
        if a == 0:
            return b
        return gcd(b % a, a)

    def lcm(a, b):
        return (a * b) // gcd(a, b)

    def canonical(matrix):
        n = len(matrix)
        order = []
        for i in range(n):
            row_sum = sum(matrix[i])
            if row_sum == 0:
                row_sum += 1
                order.append(i)
                matrix[i][i] = 1
            elif row_sum == matrix[i][i]:
                order.append(i)

            for j in range(n):
                matrix[i][j] = Fraction(matrix[i][j], row_sum)
        abs_states = len(order)
        order += [i for i in range(n) if i not in order]
        return [[matrix[order[i]][order[j]] for j in range(n)] for i in range(n)], abs_states

    # Calculate count based on the number of rows with a sum of zero
    count = sum(1 for row in m if sum(row) == 0)

    # Check if the sum of the first row is zero
    if sum(m[0]) == m[0][0]:
        # Return a specific list as described
        return [1] + [0] * (count - 1) + [1]

    m, abs_states = canonical(matrix=m)
    I = index(m, 0, abs_states, 0, abs_states)
    A = index(m, abs_states, len(m), 0, abs_states)
    B = index(m, abs_states, len(m), abs_states, len(m))
    F = inverse([[(Fraction(1, 1) if i == j else Fraction(0, 1)) - B[i][j] for i in range(len(B))] for j in range(len(B))])
    FA = mul(F, A)

    req = FA[0]
    res = sum(req)
    req = [Fraction(i, res) for i in req]
    g = 1
    for i in req:
        g = lcm(g, i.denominator)

    final_ans = []
    for i in req:
        final_ans.append(i.numerator * (g // i.denominator))

    return final_ans + [g]

def index(matrix, i1, i2, j1, j2):
    return [[matrix[i][j] for j in range(j1, j2)] for i in range(i1, i2)]
def determinant(matrix):
    n = len(matrix)
    if n == 1:
        return matrix[0][0]
    if n == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    res = 0
    for i in range(n):
        res += (-1)**i * matrix[0][i] * determinant(minor_matrix(matrix, 0, i))
    return res
def minor_matrix(matrix, row, col):
    return [[matrix[i][j] for j in range(len(matrix)) if j != col] for i in range(len(matrix)) if i != row]
def inverse(matrix):
	det = determinant(matrix)
	n = len(matrix) 
	if n == 1:
		return [[Fraction(1, det)]]
	inv = [[Fraction((-1)**(i+j) * determinant(minor_matrix(matrix, i, j)), det) for j in range(n)] for i in range(n)]
	return inv
def index(matrix, i1, i2, j1, j2):
    return [[matrix[i][j] for j in range(j1, j2)] for i in range(i1, i2)]
def mul(mat1, mat2):
    return [[sum([mat1[i][k] * mat2[k][j] for k in range(len(mat1))]) for j in range(len(mat2[0]))] for i in range(len(mat1))]
