openMenu.addEventListener('click', () => {
    menu.style.display = 'flex'
    menu.style.left = (menu.offsetWidth * -1) + 'px'
    setTimeout(() => {
        menu.style.opacity = '1'
        menu.style.left = '0'
    }, 10)
})
closeMenu.addEventListener('click', () => {

    menu.style.left = (menu.offsetWidth * -1) + 'px'
    menu.style.opacity = '0'
    setTimeout(() => {
        menu.removeAttribute('style')
    }, 200)
})