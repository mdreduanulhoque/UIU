document.getElementById("submit").addEventListener("click", function () {
    let bill = Number(document.getElementById("bill").value)
    let tip = Number(document.getElementById("tip").value)

    let tip_amount = Math.round(bill * (tip / 100))
    let total_bill = Math.round(tip_amount + bill)

    document.getElementById("show-tip").innerHTML = `<b>
    Initial Bill : ${bill} <br>
    Tip amount : ${tip_amount} <br>
    Total Bill : ${total_bill}
    </b>`
})