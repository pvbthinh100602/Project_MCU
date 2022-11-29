# Project_MCU
Button1: Chuyển mode auto -> manual -> tuning -> auto.

Button2: Khi ở manual mode và tuning mode, dùng để chuyển đèn mỗi lần nhấn.
(Đỏ -> xanh -> vàng)
Button3: Khi ở tuning, dùng để tăng giá trị từ 1 tới 99.
(Có thể sẽ hiện thực double click để accept giá trị đó.)

Pedestrian button: khi nhấn nút này đèn của ng đi bộ sẽ hiển thị theo đèn trên
tuyến đường. Buzzer sẽ kêu khi đèn ng đi đường là đèn xanh và khi counter
của đèn xanh càng giảm thì buzzer kêu càng to.

Lưu ý duration: đỏ = xanh + vàng (đỏ >= 2)

Khi ở trạng thái tuning nếu ng dùng chỉnh duration sai qui luật trên thì hệ thống
phải tự động điều chỉnh (sẽ cập nhật chi tiết thêm.)
