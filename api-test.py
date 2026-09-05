import requests

data = {
    "temperature": 28.5,
    "humidity": 72
}

response = requests.post(
    "http://127.0.0.1:5000/data",
    json=data
)

print(response.json())