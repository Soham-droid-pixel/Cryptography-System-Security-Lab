import socket

n = 3233
e = 17
d = 2753

def sign_message(message, d, n):
    signature = []
    for char in message:
        ascii_value = ord(char)
        encrypted_num = pow(ascii_value, d, n)
        signature.append(encrypted_num)
    return signature

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('localhost', 5000))

msg = "HELLO"
signature = sign_message(msg, d, n)

sig_str = ",".join(map(str, signature))
payload = f"{msg}|{sig_str}"

client.send(payload.encode())
print(f"Sent Message: {msg}")
print(f"Sent Signature: {sig_str}")

client.close()