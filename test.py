import qrcode

# 格式：WIFI:T:WPA;S:网络名;P:密码;H:;
wifi_config = "WIFI:T:WPA;S:刘禹岐是混蛋;P:12345678;;"

qr = qrcode.QRCode()
qr.add_data(wifi_config)
img = qr.make_image()
img.save("嘻嘻.png")