<img width="1919" height="1025" alt="image" src="https://github.com/user-attachments/assets/4c6d3b9a-a464-4212-8d27-1e95700684a8" /># HomeWork01-Security
# Lê Quốc Trung - K225480106065
## Các kiểu mã hóa
## 1. Mã hóa Caesar (Caesar Cipher)
### Thuật toán mã hóa  
Dịch chuyển mỗi ký tự P → C = (P + k) mod 26
### Thuật toán giải mã
C = (C - k) mod 26
### Không gian khóa
25 khóa khả dĩ (k = 1…25)
### Cách phá mã (không cần khóa)
Thử tất cả khóa (brute-force), phân tích tần suất chữ cái
### Ảnh minh họa mã hóa
<img width="1919" height="1027" alt="image" src="https://github.com/user-attachments/assets/b94e2d79-e1b8-456a-8ba7-37c3c67e7e7e" />

### Ảnh minh họa giải mã
<img width="1919" height="959" alt="image" src="https://github.com/user-attachments/assets/c5c3ebbb-10b5-44a6-a2ee-465745374ab2" />

## 2. Mã hóa Affine (Affine Cipher)
### Thuật toán mã hóa  
P → C = (a*P + b) mod 26, a và b là khóa
### Thuật toán giải mã
P = a⁻¹ * (C - b) mod 26
### Không gian khóa
a có 12 giá trị khả dĩ (cùng nguyên tố với 26), b có 26 giá trị → 312 khóa
### Cách phá mã (không cần khóa)
Phân tích tần suất, thử tất cả khóa a,b
### Ảnh minh họa mã hóa
<img width="1919" height="1025" alt="image" src="https://github.com/user-attachments/assets/28cce587-462e-4f2d-b255-1d59feca0018" />

### Ảnh minh họa giải mã
<img width="1919" height="975" alt="image" src="https://github.com/user-attachments/assets/063f3483-d3a1-4565-8174-782a1235d58d" />

## 3. Mã hóa hoán vị (Transposition Cipher)   
### Thuật toán mã hóa  
Sắp xếp lại vị trí ký tự theo một khóa k
### Thuật toán giải mã
Đảo lại vị trí theo khóa k
### Không gian khóa
Với n ký tự: n! hoán vị
### Cách phá mã (không cần khóa)
Phân tích cấu trúc, tìm các mẫu lặp, đoán cấu trúc cột hoặc hàng
### Ảnh minh họa mã hóa
<img width="1919" height="1028" alt="image" src="https://github.com/user-attachments/assets/b75a39dc-23d0-46cc-a04d-ff517858fa2e" />

### Ảnh minh họa giải mã
<img width="1919" height="1027" alt="image" src="https://github.com/user-attachments/assets/36b69a1e-81e4-4e14-a864-bf3a6d9d45a0" />

## 4. Mã hóa Vigenère (Vigenère Cipher)
### Thuật toán mã hóa  
P + K (mod 26), K là chuỗi ký tự lặp lại
### Thuật toán giải mã  
C - K (mod 26)
### Không gian khóa  
Với khóa dài m: 26^m khả năng
### Cách phá mã (không cần khóa)
Phân tích Kasiski, Friedman, thống kê tần suất bậc cao
### Ảnh minh họa mã hóa
<img width="1919" height="977" alt="image" src="https://github.com/user-attachments/assets/066faa22-fd01-415b-87a0-bc33b2aeb2e5" />

### Ảnh minh họa giải mã
<img width="1919" height="977" alt="image" src="https://github.com/user-attachments/assets/4bbb3c4d-7b66-473a-b9ca-a53269b5c773" />

## 5. Mã hóa Playfair (Playfair Cipher)
### Thuật toán mã hóa  
Chia bản rõ thành digraph, dùng ma trận 5x5 để thay thế theo quy tắc hàng/cột/rect
### Thuật toán giải mã
Áp dụng quy tắc đảo ngược để giải mã
### Không gian khóa
25! ma trận khả dĩ (sắp xếp chữ cái trong ma trận 5x5)
### Cách phá mã (không cần khóa)
Phân tích tần suất digraph, suy đoán từ thường dùng, mẫu digraph phổ biến
### Ảnh minh họa mã hóa
<img width="1919" height="973" alt="image" src="https://github.com/user-attachments/assets/c506c7de-371a-4114-aaae-a69507ba095a" />

### Ảnh minh họa giải mã
<img width="1919" height="1019" alt="image" src="https://github.com/user-attachments/assets/8ed92af1-75a9-40ac-b944-db62fc4a9a86" />
