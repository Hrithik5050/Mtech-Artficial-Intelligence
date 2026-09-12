import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('insurance.csv')


print(data.charges.describe())

def loss_function(m, b, points):
    total_loss = 0
    N = len(points)

    for i in range(N):
        x = points.iloc[i].age
        y = points.iloc[i].charges

        prediction = m * x + b
        total_loss += (y - prediction) ** 2

    return total_loss / N


def gradient_descent(m_now, b_now, learning_rate, points):

    m_gradient = 0
    b_gradient = 0
    N = len(points)

    for i in range(N):

        x = points.iloc[i].age
        y = points.iloc[i].charges

        prediction = m_now * x + b_now
        error = y - prediction

        m_gradient += -(2/N) * x * error
        b_gradient += -(2/N) * error

    m_now = m_now - learning_rate * m_gradient
    b_now = b_now - learning_rate * b_gradient

    return m_now, b_now


m = 0
b = 0

learning_rate = 0.0001
epochs = 500

loss_history = []

for i in range(epochs):

    m, b = gradient_descent(
        m,
        b,
        learning_rate,
        data
    )

    loss = loss_function(m, b, data)
    loss_history.append(loss)


print("m =", m)
print("b =", b)
print("Final Loss =", loss_history[-1])


# Data + regression line
plt.scatter(data.age, data.charges)

plt.plot(
    data.age,
    m * data.age + b,color='red'
)

plt.xlabel("Age")
plt.ylabel("Charges")
plt.show()


