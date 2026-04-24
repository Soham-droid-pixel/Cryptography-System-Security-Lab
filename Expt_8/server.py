import socket

n = 3233
e = 17

def verify_signature(message, signature, e, n):
    decrypted_message = ""
    for num in signature:
        ascii_value = pow(num, e, n)
        character = chr(ascii_value)
        decrypted_message += character
    return decrypted_message == message

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('localhost', 5000))
server.listen(1)

print("Server listening on port 5000...")
conn, addr = server.accept()

data = conn.recv(1024).decode()
msg, sig_str = data.split('|')

signature = [int(x) for x in sig_str.split(',')]

print(f"Received Message: {msg}")

if verify_signature(msg, signature, e, n):
    print("Signature Verified! The message is authentic and from the client.")
else:
    print("Verification Failed! The signature does not match.")

conn.close()
server.close()